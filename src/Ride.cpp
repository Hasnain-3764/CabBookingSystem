#include "Ride.h"
#include <iostream>
#include <chrono>
#include <thread>


Ride::Ride(int rideId, int riderId, int driverId)
    :rideId(rideId), riderId(riderId), driverId(driverId), fare(0.0) {}

void Ride::startRide(){
    startTime = std::chrono::steady_clock::now();
    std::time_t start_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << "Ride started for Rider " << riderId << " with Driver " << driverId << " at start time "<< std::ctime(&start_time_t)  << std::endl;
    // simulating ride;
    std::this_thread::sleep_for(std::chrono::seconds(5+rand()%6));
}

void Ride::completeRide(){
    endTime = std::chrono::steady_clock::now();
    fare = 100.0 + rand() % 50;
    std::time_t end_time_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << "Ride completed with Fare: ₹" << fare << " at time "<< std::ctime(&end_time_t) << std::endl;
}

double Ride::getFare() const {
    return fare;
}

void Ride::printRideDetails() const {
    std::cout << "Ride ID: " << rideId << ", Rider ID: " << riderId << ", Driver ID: " << driverId << std::endl;
}