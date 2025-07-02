#include "User.h"

User::User(int id, std::string name, std::string location)
    : id(id), name(name), location(location) {}

int User::getId() const { return id; }
std::string User::getName() const { return name; }
std::string User::getLocation() const { return location; }
