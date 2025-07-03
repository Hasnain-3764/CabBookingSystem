#pragma once
#include <sqlite3.h>
#include <iostream>
#include <vector>
#include <string>
#include "Driver.h"
#include "Rider.h"
#include "Ride.h"

class Database{
private:
    sqlite3* db;
    std::string dbName;
public:
    Database(const std::string& dbName);
    ~Database();
    bool open();
    void close();
    bool createTable();
    bool insertRider(const Rider& rider);
    bool insertDriver(const Driver& driver);
    bool insertRide(const Ride& ride);
    void fetchRides();
    sqlite3* getDb() const;

};