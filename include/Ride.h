#pragma once
#include <string>
#include <iostream>
#include <chrono>

class Ride{
private:
    int rideId;
    int riderId;
    int driverId;
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::time_point<std::chrono::steady_clock> endTime;
    double fare;

public:
    Ride(int rideId, int riderId, int driverId);
    void startRide();
    void completeRide();
    double getFare() const;
    void printRideDetails() const;
};