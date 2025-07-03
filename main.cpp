// Start of Cab Booking Project
#include <iostream>
#include "RideManager.h"
#include "User.h"
#include "Rider.h"
#include "Driver.h"
#include "Ride.h"
#include <thread>
#include "database.h"

using namespace std;
RideManager rideManager;


int main() {

    Database db("cab_booking.db");
    if(!db.open()){
        cout<<"Error opening database."<<endl;
        return 1;
    }

    if(!db.createTable()){
        cout<<"Error creating tables."<<endl;
        return 1;
    }
    
     // Insert riders and get their IDs
    Rider r1("Hasnain", "Delhi", true);
    db.insertRider(r1);  
    long rider1Id = sqlite3_last_insert_rowid(db.getDb());  
    std::cout << "Rider 1 ID: " << rider1Id << std::endl;

    Rider r2("Tarun", "Mumbai", false);
    db.insertRider(r2); 
    long rider2Id = sqlite3_last_insert_rowid(db.getDb());  // Get the rider's ID
    std::cout << "Rider 2 ID: " << rider2Id << std::endl;

    // // Insert drivers (driver IDs will be fetched similarly)
    // Driver d1("Ravi", "Delhi", true);
    // db.insertDriver(d1);

    // Driver d2("Kaju", "Mumbai", true);
    // db.insertDriver(d2);

    // // Now pass the rider IDs to the requestRide function
    // rideManager.requestRide(rider1Id);  // Passing Rider 1's ID
    // rideManager.requestRide(rider2Id);  // Passing Rider 2's ID

    std::cout << "\n--- Ride History ---\n";
    rideManager.viewRides();


    return 0;
}