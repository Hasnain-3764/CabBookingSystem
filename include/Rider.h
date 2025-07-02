#pragma once
#include "User.h"

class Rider : public User {
private:
    bool isVIP;
public:
    Rider(int id, std::string name, std::string location, bool isVIP);
    bool getIsVIP() const;
    void requestRide();
    void upgradeToVIP();  // Method to upgrade to VIP

};