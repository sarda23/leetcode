// Design a Parking Lot System

// Problem: Design a parking lot system where:

//     There are multiple types of vehicles: bike, car, and bus.
//     A parking lot can have different sizes of parking spots: small, medium, and large.
//     A vehicle can only park in a spot of appropriate size:
//         Bikes can park in any spot.
//         Cars need at least a medium spot.
//         Buses need a large spot.
//     The system should be able to park a vehicle, remove it, and track the available parking spots.


    #include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

enum VehicleType { BIKE, CAR, BUS }; // Enum to define vehicle types
enum SpotSize { SMALL, MEDIUM, LARGE }; // Enum to define parking spot sizes

// Base class for Vehicle
class Vehicle {
protected:
    VehicleType type;
public:
    Vehicle(VehicleType type) : type(type) {}
    virtual VehicleType getType() { return type; }
};

// Different vehicle types
class Bike : public Vehicle {
public:
    Bike() : Vehicle(BIKE) {}
};

class Car : public Vehicle {
public:
    Car() : Vehicle(CAR) {}
};

class Bus : public Vehicle {
public:
    Bus() : Vehicle(BUS) {}
};

// ParkingSpot class to define a spot and its properties
class ParkingSpot {
    SpotSize size;
    bool isOccupied;
public:
    ParkingSpot(SpotSize size) : size(size), isOccupied(false) {}
    SpotSize getSize() { return size; }
    bool isAvailable() { return !isOccupied; }
    void occupySpot() { isOccupied = true; }
    void freeSpot() { isOccupied = false; }
};

// ParkingLot class that manages parking spots and vehicles
class ParkingLot {
    map<SpotSize, vector<ParkingSpot>> spots;
public:
    ParkingLot(int smallCount, int mediumCount, int largeCount) {
        for (int i = 0; i < smallCount; ++i) spots[SMALL].push_back(ParkingSpot(SMALL));
        for (int i = 0; i < mediumCount; ++i) spots[MEDIUM].push_back(ParkingSpot(MEDIUM));
        for (int i = 0; i < largeCount; ++i) spots[LARGE].push_back(ParkingSpot(LARGE));
    }

    bool parkVehicle(Vehicle *vehicle) {
        SpotSize requiredSpot;
        
        switch (vehicle->getType()) {
            case BIKE:
                requiredSpot = SMALL;
                break;
            case CAR:
                requiredSpot = MEDIUM;
                break;
            case BUS:
                requiredSpot = LARGE;
                break;
        }

        // Try to find an appropriate spot for the vehicle
        for (auto &spot : spots[requiredSpot]) {
            if (spot.isAvailable()) {
                spot.occupySpot();
                cout << "Vehicle parked in a " << (requiredSpot == SMALL ? "Small" : requiredSpot == MEDIUM ? "Medium" : "Large") << " spot." << endl;
                return true;
            }
        }

        cout << "No available spot for the vehicle!" << endl;
        return false;
    }

    void removeVehicle(Vehicle *vehicle) {
        SpotSize occupiedSpot;

        switch (vehicle->getType()) {
            case BIKE:
                occupiedSpot = SMALL;
                break;
            case CAR:
                occupiedSpot = MEDIUM;
                break;
            case BUS:
                occupiedSpot = LARGE;
                break;
        }

        // Free the first occupied spot of the correct type
        for (auto &spot : spots[occupiedSpot]) {
            if (!spot.isAvailable()) {
                spot.freeSpot();
                cout << "Vehicle removed from a " << (occupiedSpot == SMALL ? "Small" : occupiedSpot == MEDIUM ? "Medium" : "Large") << " spot." << endl;
                return;
            }
        }

        cout << "No vehicle found to remove!" << endl;
    }
};

// Main function
int main() {
    // Create a parking lot with 5 small, 5 medium, and 2 large spots
    ParkingLot parkingLot(5, 5, 2);

    // Create different vehicles
    Vehicle *bike = new Bike();
    Vehicle *car = new Car();
    Vehicle *bus = new Bus();

    // Park vehicles
    parkingLot.parkVehicle(bike); // Should park in a small spot
    parkingLot.parkVehicle(car);  // Should park in a medium spot
    parkingLot.parkVehicle(bus);  // Should park in a large spot

    // Remove vehicles
    parkingLot.removeVehicle(bike);  // Removes the bike
    parkingLot.removeVehicle(car);   // Removes the car
    parkingLot.removeVehicle(bus);   // Removes the bus

    // Clean up
    delete bike;
    delete car;
    delete bus;

    return 0;
}

// Explanation:

//     Vehicle Class: Represents the base class for different types of vehicles (bike, car, bus).
//     ParkingSpot Class: Represents a parking spot. A spot can be small, medium, or large and has an availability status.
//     ParkingLot Class: Manages the available parking spots. It can park and remove vehicles based on their size.
//     The main() function demonstrates how to park and remove different vehicles in the parking lot.