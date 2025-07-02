#pragma once
#include <vector>
#include <string>
#include <mutex>

class RideManager{
private:
    // std::vector<Rider> riders;
    // std::vector<Driver> drivers;
    // std::vector<Ride> rideHistory;
    std::mutex rideMutex;
public:
    void registerRider(std::string name, std::string location);
    void registerDriver(std::string name, std::string location);
    void requestRide(int riderId);
    void viewRides() const;
};