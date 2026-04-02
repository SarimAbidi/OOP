//1. Smart Parking Garage Management
//A new multi-level smart parking garage in your city wants to replace its manual system with a basic software model. The garage has multiple floors, and each floor has different types of parking spots (for cars, bikes, and electric cars). Each vehicle that enters is assigned a unique ticket ID, arrival time, and a specific slot. Electric vehicles additionally require information about charging duration. The garage also wants to track how many vehicles are currently parked of each type and automatically free the slot when a vehicle leaves.
//
//Requirements:
//
//Design a base class Vehicle that stores common information for all vehicles (e.g., registration number, owner name).
//Create derived classes Car, Bike, and ElectricCar that extend Vehicle with specific attributes (e.g., ElectricCar has a charging duration).
//Design a class ParkingSlot that:
//Is responsible for storing which Vehicle is parked in it.
//Has information like floor number, slot number, and slot type.
//Ensures that once a slot is occupied, it cannot be assigned to another vehicle until it is freed (use encapsulation to protect slot state).
//Design a class Ticket that is created when a vehicle enters:
//Must be initialized using a constructor with a unique ticket ID, entry time, and association to the Vehicle and the ParkingSlot (you may use identifiers, objects, or references but do NOT use pointers).
//When a vehicle leaves, a method should compute the total parked duration and (optionally) print a simple bill.
//Use constructors to ensure that:
//A Vehicle object must always be created with valid registration number and owner name.
//A ParkingSlot cannot be created without specifying its floor, slot number, and type.
//Use encapsulation to:
//Prevent direct modification of ParkingSlot occupancy from outside; provide methods like assignVehicle() and removeVehicle().
//Control access to billing-related data inside Ticket.
//Assume this is a console application; you do not need to implement real time or user input, but you must structure the classes so a tester can:
//Create some vehicles of different types.
//Assign them slots, generate tickets.
//Simulate exit and check that slot freeing and counts are updated correctly.
//Specify all classes, their relationships, constructors, and key methods. You do not need to write the full user interface, just the class designs and core logic.
#include <iostream>
#include <string>

class Vehicle {
protected:
    std::string regNumber;
    std::string ownerName;
public:
    Vehicle(const std::string& reg, const std::string& owner)
        : regNumber(reg), ownerName(owner) {}

    std::string getRegNumber() const { return regNumber; }
    std::string getOwnerName() const { return ownerName; }
};

class Car : public Vehicle {
public:
    Car(const std::string& reg, const std::string& owner)
        : Vehicle(reg, owner) {}
    std::string getType() const { return "Car"; }
};

class Bike : public Vehicle {
public:
    Bike(const std::string& reg, const std::string& owner)
        : Vehicle(reg, owner) {}
    std::string getType() const { return "Bike"; }
};

class ElectricCar : public Vehicle {
    int chargingMinutes;
public:
    ElectricCar(const std::string& reg, const std::string& owner, int minutes)
        : Vehicle(reg, owner), chargingMinutes(minutes) {}
    std::string getType() const { return "ElectricCar"; }
    int getChargingMinutes() const { return chargingMinutes; }
};

class ParkingSlot {
    int floor;
    int slotNumber;
    std::string slotType;
    bool occupied;
    std::string currentVehicleReg;
    std::string currentVehicleType;
    int currentChargingMinutes;
public:
    ParkingSlot(int f, int num, const std::string& type)
        : floor(f), slotNumber(num), slotType(type),
          occupied(false), currentVehicleReg(""),
          currentVehicleType(""), currentChargingMinutes(0) {}

    bool isOccupied() const { return occupied; }
    std::string getSlotType() const { return slotType; }

    bool assignVehicle(const Vehicle& v, const std::string& type, int chargingMinutes = 0) {
        if (occupied) return false;
        occupied = true;
        currentVehicleReg = v.getRegNumber();
        currentVehicleType = type;
        currentChargingMinutes = chargingMinutes;
        return true;
    }

    void removeVehicle() {
        occupied = false;
        currentVehicleReg = "";
        currentVehicleType = "";
        currentChargingMinutes = 0;
    }

    std::string getCurrentVehicleReg() const { return currentVehicleReg; }
    std::string getCurrentVehicleType() const { return currentVehicleType; }
    int getCurrentChargingMinutes() const { return currentChargingMinutes; }

    int getFloor() const { return floor; }
    int getSlotNumber() const { return slotNumber; }
};

class Ticket {
    int ticketId;
    std::string entryTime;
    std::string exitTime;
    ParkingSlot& slot;
    const Vehicle& vehicle;
    std::string vehicleType;
    int chargingMinutes;
    bool closed;
public:
    Ticket(int id, const std::string& entry,
           const Vehicle& v, ParkingSlot& s,
           const std::string& type, int minutes = 0)
        : ticketId(id), entryTime(entry),
          slot(s), vehicle(v),
          vehicleType(type),
          chargingMinutes(minutes),
          closed(false) {}

    void close(const std::string& exit) {
        exitTime = exit;
        closed = true;
        slot.removeVehicle();
        // dummy duration and bill
        std::cout << "Ticket " << ticketId << " closed for vehicle "
                  << vehicle.getRegNumber()
                  << " (" << vehicleType << ")"
                  << " from " << entryTime << " to " << exitTime;
        if (vehicleType == "ElectricCar") {
            std::cout << ", charging minutes: " << chargingMinutes;
        }
        std::cout << "\n";
    }
};

int main() {
    ParkingSlot slot1(1, 1, "Car");
    ParkingSlot slot2(1, 2, "Car");

    Car c1("ABC-123", "Ali");
    ElectricCar e1("EV-999", "Sara", 60);

    int nextTicketId = 1;

    if (slot1.assignVehicle(c1, c1.getType())) {
        Ticket t1(nextTicketId++, "10:00", c1, slot1, c1.getType());
        t1.close("11:00");
    }

    if (slot2.assignVehicle(e1, e1.getType(), e1.getChargingMinutes())) {
        Ticket t2(nextTicketId++, "10:05", e1, slot2, e1.getType(), e1.getChargingMinutes());
        t2.close("11:30");
    }

    return 0;
}