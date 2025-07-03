#include <database.h>

Database::Database(const std::string& dbName)
    : db(nullptr), dbName(dbName) {}

Database::~Database(){
    close();
}

bool Database::open(){
    int rc = sqlite3_open(dbName.c_str(), &db);
    if(rc){
        std::cerr << "Couldn't Open DataBase rn: "<<sqlite3_errmsg(db) << std::endl;
        return false;
    }
    return true;
}


void Database::close(){
    if(db){
        sqlite3_close(db);
    }
}

sqlite3* Database::getDb() const { 
    return db; 
}

bool Database::createTable(){
    const char* createRidersTableSQL = "CREATE TABLE IF NOT EXISTS riders (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, location TEXT NOT NULL, isVIP INTEGER);";
    const char* createDriversTableSQL = "CREATE TABLE IF NOT EXISTS drivers (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, location TEXT NOT NULL, isAvailable INTEGER);";
    const char* createRidesTableSQL = "CREATE TABLE IF NOT EXISTS rides (rideId INTEGER PRIMARY KEY AUTOINCREMENT, riderId INTEGER, driverId INTEGER, startTime TEXT, endTime TEXT, fare REAL);";
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, createRidersTableSQL, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error 1: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }

    rc = sqlite3_exec(db, createDriversTableSQL, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error 2: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }

    rc = sqlite3_exec(db, createRidesTableSQL, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error 3: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool Database::insertRider(const Rider& rider) {
    std::string sql = "INSERT INTO riders (name, location, isVIP) VALUES ('" + rider.getName() + "', '" + rider.getLocation() + "', " + std::to_string(rider.getIsVIP()) + ");";
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error 4: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool Database::insertDriver(const Driver& driver){
    std::string sql = "INSERT INTO drivers (name, location, isAvailable) VALUES ('" + driver.getName() + "', '" + driver.getLocation() + "', " + std::to_string(driver.getIsAvailable()) + ");";
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error 5: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool Database::insertRide(const Ride& ride){
    auto startTime = std::chrono::system_clock::to_time_t(ride.getStartTime());
    auto endTime = std::chrono::system_clock::to_time_t(ride.getEndTime());
    double fare = ride.getFare();
    std::string sql = "INSERT INTO rides (riderId, driverId, startTime, endTime, fare) VALUES (" + std::to_string(ride.getRiderId()) + ", " + std::to_string(ride.getDriverId()) + ", '" + std::to_string(startTime) + "', '" + std::to_string(endTime) + "', " + std::to_string(fare) + ");";
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error 6: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

void Database::fetchRides() {
    const char* sql = "SELECT * FROM rides;";
    sqlite3_stmt* stmt;
    
    // Use sqlite3_prepare_v2 for UTF-8 strings (this is the correct version)
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to fetch rides: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // Fetch and print the results row by row
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int rideId = sqlite3_column_int(stmt, 0);
        int riderId = sqlite3_column_int(stmt, 1);
        int driverId = sqlite3_column_int(stmt, 2);
        std::cout << "Ride ID: " << rideId << ", Rider Id: " << riderId << ", Driver ID: " << driverId << std::endl;
    }

    // Clean up
    sqlite3_finalize(stmt);
}

