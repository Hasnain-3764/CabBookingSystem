#include "Driver.h"
#include <iostream>

Driver::Driver(int id, std::string name, std::string location, bool isAvailable)
    : User(id, name, location), isAvailable(isAvailable) {}

bool Driver::getIsAvailable() const {
    return isAvailable;
}

void Driver::acceptRide() {
    if (isAvailable) {
        std::cout << getName() << " has accepted the ride." << std::endl;
        isAvailable = false;  // Mark the driver as unavailable after accepting a ride
    } else {
        std::cout << getName() << " is currently unavailable." << std::endl;
    }
}

void Driver::updateLocation(const std::string& newLocation) {
    std::cout << getName() << "'s location is updated to " << newLocation << std::endl;
}
