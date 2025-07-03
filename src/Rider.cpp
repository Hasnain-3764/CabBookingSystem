#include "Rider.h"
#include <iostream>

Rider::Rider(std::string name, std::string location, bool isVIP)
    :User(name, location), isVIP(isVIP) {}

Rider::Rider(int id, std::string name, std::string location, bool isVIP)
    :User(id, name, location), isVIP(isVIP) {}

bool Rider::getIsVIP() const {
    return isVIP;
}

void Rider::requestRide() {
    std::cout << "Ride requested by " << getName() << " from " << getLocation() << std::endl;
    if (isVIP) {
        std::cout << "This is a VIP rider." << std::endl;
    }
}

void Rider::upgradeToVIP() {
    isVIP = true;
    std::cout << "Congratulations! " << getName() << " is now a VIP rider." << std::endl;
}