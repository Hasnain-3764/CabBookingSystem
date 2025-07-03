#pragma once
#include <string>
#include <iostream>
#include <chrono>

class Ride{
private:
    int rideId;
    int riderId;
    int driverId;
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::time_point<std::chrono::system_clock> endTime;
    double fare;

public:
    Ride(int riderId, int driverId);
    Ride(int rideId, int riderId, int driverId);
    void startRide();
    void completeRide();
    double getFare() const;
    void printRideDetails() const;
    std::chrono::time_point<std::chrono::system_clock> getStartTime() const;
    std::chrono::time_point<std::chrono::system_clock> getEndTime() const;
    int getRideId() const;
    int getRiderId() const;
    int getDriverId() const;
};