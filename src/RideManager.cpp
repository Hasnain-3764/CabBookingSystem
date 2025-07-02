#include "RideManager.h"
#include <iostream>
#include <thread>

void RideManager::registerRider(int id, std::string name, std::string location, bool isVIP){
    riders.push_back(Rider(id, name, location, isVIP));
    std::cout << "Rider " << name << " registered." << std::endl;
}

void RideManager::registerDriver(int id, std::string name, std::string location, bool isAvailable){
    drivers.push_back(Driver(id, name, location, isAvailable));
    std::cout << "Driver " << name << " registered." << std::endl;
}

void RideManager::requestRide(int riderId){
    std::lock_guard<std::mutex> lock(rideMutex);
    Rider* rider = nullptr;
    for(auto& r: riders){
        if(r.getId() == riderId){
            rider = &r;
            break;
        }
    }
    if (!rider) {
        std::cout << "Rider not found!" << std::endl;
        return;
    }
    Driver* driver = nullptr;
    for(auto &d:drivers){
        if(d.getIsAvailable()){
            driver = &d;
            // driver accepts the ride
            driver->acceptRide();
            break;
        }
    }
    if(!driver){
        std::cout<< "No available drivers!" << std::endl;
        return;
    }
    Ride ride(rideHistory.size()+1, riderId, driver->getId());
    ride.startRide();
    ride.completeRide();
    rideHistory.push_back(ride);
    std::cout << "Ride completed. Fare: ₹" << ride.getFare() << std::endl;
}

void RideManager::viewRides() const {
    for(const auto& ride : rideHistory){
        ride.printRideDetails();
    }
}
