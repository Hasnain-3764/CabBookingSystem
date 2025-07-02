// Start of Cab Booking Project
#include <iostream>
#include <RiderManager.h>

using namespace std;
RideManager manager;

int main() {

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