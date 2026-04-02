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
