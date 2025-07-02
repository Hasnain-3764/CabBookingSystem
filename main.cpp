// Start of Cab Booking Project
#include <iostream>
#include <RideManager.h>
#include "User.h"
#include "Rider.h"
#include "Driver.h"
#include "Ride.h"
#include <thread>

using namespace std;
RideManager rideManager;

void requestRideInThread(RideManager& rideManager, int riderId) {
    rideManager.requestRide(riderId);
}


int main() {

    // User user1(1, "John Doe", "Delhi");
    // std::cout << "User ID: " << user1.getId() << std::endl;
    // std::cout << "User Name: " << user1.getName() << std::endl;
    // std::cout << "User Location: " << user1.getLocation() << std::endl;


    // Rider rider1(1, "Alice", "Delhi", true);
    // Rider rider2(2, "Bob", "Mumbai", false);
    // std::cout << "Rider 1 - VIP Status: " << (rider1.getIsVIP() ? "Yes" : "No") << std::endl;
    // rider1.requestRide();
    // std::cout << "Rider 2 - VIP Status: " << (rider2.getIsVIP() ? "Yes" : "No") << std::endl;
    // rider2.requestRide();
    // rider2.upgradeToVIP();


    // Driver driver1(1, "John", "Delhi", true);
    // Driver driver2(2, "Mike", "Mumbai", false);
    // std::cout << "Driver 1 - Available: " << (driver1.getIsAvailable() ? "Yes" : "No") << std::endl;
    // driver1.acceptRide();  // Driver accepts ride
    // std::cout << "Driver 2 - Available: " << (driver2.getIsAvailable() ? "Yes" : "No") << std::endl;
    // driver2.acceptRide();  // Driver is unavailable  
    // driver1.updateLocation("Noida");  // Update location


    // Ride ride1(1, 1, 1);  // Ride ID: 1, Rider ID: 1, Driver ID: 1
    // ride1.printRideDetails();
    // // Start and complete the ride
    // ride1.startRide();
    // ride1.completeRide();

    // // Register some riders and drivers
    // rideManager.registerRider(1, "Alice", "Delhi", true);
    // rideManager.registerRider(2, "Bob", "Mumbai", false);
    // rideManager.registerDriver(1, "John", "Delhi", true);
    // rideManager.registerDriver(2, "Mike", "Mumbai", true);
    // // Rider requests a ride
    // // rideManager.requestRide(1);  // Alice requests a ride
    // // rideManager.requestRide(2);

    // // Create threads for ride requests
    // std::thread rideThread1(requestRideInThread, std::ref(rideManager), 1);  // Alice requests a ride
    // std::thread rideThread2(requestRideInThread, std::ref(rideManager), 2);  // Bob requests a ride

    // // Wait for both threads to finish
    // rideThread1.join();
    // rideThread2.join();

    // // View ride history
    // std::cout << "\n--- Ride History ---\n";
    // rideManager.viewRides();


    int choice;
    while(true){
        cout << "\n--- Cab Booking System ---\n";
        cout << "1. Register Rider\n";
        cout << "2. Register Driver\n";
        cout << "3. Request Ride\n";
        cout << "4. View Rides\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Registering Rider...\n"; 
                // manager.registerRider();
                break;
            }
            case 2: {
                cout << "Registering Driver...\n"; 
                // manager.registerDriver();
                break;
            }
            case 3: cout << "Requesting Ride...\n"; break;
            case 4: cout << "Viewing Rides...\n"; break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }

    return 0;
}