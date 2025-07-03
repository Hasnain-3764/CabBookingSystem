#pragma once
#include "User.h"

class Driver : public User {
private:
    bool isAvailable;

public:
    Driver(std::string name, std::string location, bool isAvailable);
    Driver(int id, std::string name, std::string location, bool isAvailable);
    bool getIsAvailable() const;
    void acceptRide();
    void updateLocation(const std::string& newLocation);
};
