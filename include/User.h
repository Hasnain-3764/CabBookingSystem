#pragma once
#include <string>

class User{
protected:
    int id;
    std::string name;
    std::string location;
public:
    User(int id, std::string name, std::string location);
    virtual ~User(){}
    int getId() const;
    std::string getName() const;
    std::string getLocation() const;
};
