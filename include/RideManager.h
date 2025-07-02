#pragma once
#include "Ride.h"
#include "Rider.h"
#include "Driver.h"
#include <vector>
#include <mutex>
class RideManager{

private:
    std::vector<Rider> riders;
    std::vector<Driver> drivers;
    std::vector<Ride> rideHistory;
    std::mutex rideMutex;

public:
    void registerRider(int id, std::string name, std::string location, bool isVIP);
    void registerDriver(int id, std::string name, std::string location, bool isAvailable);
    void requestRide(int riderId);
    void viewRides() const;
};