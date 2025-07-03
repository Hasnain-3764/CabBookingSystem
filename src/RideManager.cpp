#include "RideManager.h"
#include <iostream>
#include <thread>
#include <database.h>

void RideManager::registerRider(int id, std::string name, std::string location, bool isVIP)
{
    Rider rider(id, name, location, isVIP);
    riders.push_back(rider);
    Database db("cab_booking.db");
    db.open();
    db.insertRider(rider);
    db.close();
    std::cout << "Rider " << name << " registered." << std::endl;
}

void RideManager::registerDriver(int id, std::string name, std::string location, bool isAvailable)
{
    Driver driver(id, name, location, isAvailable);
    drivers.push_back(driver);

    Database db_instance("cab_booking.db");
    db_instance.open();
    db_instance.insertDriver(driver);
    db_instance.close();
    std::cout << "Driver " << name << " registered." << std::endl;
}

void RideManager::requestRide(int riderId)
{
    std::lock_guard<std::mutex> lock(rideMutex);
    Rider *rider = nullptr;

    Database db("cab_booking.db");
    if (!db.open())
    {
        std::cerr << "Error opening database" << std::endl;
        return;
    }

    const std::string query = "SELECT * FROM riders WHERE id = " + std::to_string(riderId) + ";";
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db.getDb(), query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Failed to fetch rider " << sqlite3_errmsg(db.getDb()) << std::endl;
        db.close();
        return;
    }
    // If we find the rider, set the rider pointer
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        if (id == riderId)
        {
            std::string name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            std::string location = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
            bool isVIP = sqlite3_column_int(stmt, 3);
            rider = new Rider(id, name, location, isVIP); // Assume Rider constructor matches this
            std::cout << "Rider found: " << rider->getName() << std::endl;
        }
        else
        {
            std::cout << "Rider with ID " << riderId << " not found!" << std::endl;
            sqlite3_finalize(stmt);
            db.close();
            return;
        }
    }
    else
    {
        std::cout << "No rider found with ID: " << riderId << std::endl;
        sqlite3_finalize(stmt);
        db.close();
        return;
    }
    sqlite3_finalize(stmt);

    Driver *driver = nullptr;
    const std::string driverQuery = "SELECT * FROM drivers WHERE isAvailable = 1 LIMIT 1;"; // Get available driver
    rc = sqlite3_prepare_v2(db.getDb(), driverQuery.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        std::cerr << "Failed to fetch drivers: " << sqlite3_errmsg(db.getDb()) << std::endl;
        db.close();
        return;
    }

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int driverId = sqlite3_column_int(stmt, 0);
        std::string driverName = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
        std::string driverLocation = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
        bool isAvailable = sqlite3_column_int(stmt, 3);
        driver = new Driver(driverId, driverName, driverLocation, isAvailable);

        // Driver accepts the ride
        driver->acceptRide();
        std::cout << "Driver " << driver->getName() << " accepted the ride!" << std::endl;
    }
    else
    {
        std::cout << "No available drivers!" << std::endl;
        sqlite3_finalize(stmt);
        db.close();
        return;
    }
    sqlite3_finalize(stmt);

    Ride ride(riderId, driver->getId());
    ride.startRide();
    ride.completeRide();
    db.insertRide(ride);
    rideHistory.push_back(ride);
    db.close();
    std::cout << "Ride completed. Fare: ₹" << ride.getFare() << std::endl;
}

void RideManager::viewRides() const
{
    for (const auto &ride : rideHistory)
    {
        ride.printRideDetails();
    }
}
