// 6. Hotel Room Reservation with Inheritance
// A seaside hotel has three types of rooms: StandardRoom, DeluxeRoom, and SuiteRoom. Each room type has different pricing and amenities. The hotel wants a basic reservation system that captures guest details, assigns rooms, and computes total charges. However, internal pricing rules (like seasonal multipliers or discounts) must not be directly modifiable from outside the room classes.

// Requirements:

// Create a base class Room with:
// Room number, base price per night, and occupancy status.
// A constructor that initializes the room number and base price.
// Create derived classes:
// StandardRoom, DeluxeRoom, and SuiteRoom that:
// Set different base prices and maybe extra charges (e.g., complimentary breakfast, ocean-view surcharge) in their constructors.
// Provide their own methods for calculating price (for example, calculatePrice or type-specific helpers).
// Create a class Reservation that:
// Ties a guest name to a Room for a certain number of nights.
// In its constructor, ensures that a room is not already occupied before confirming.
// Calculates the total cost using appropriate room-type-specific logic.
// Use encapsulation to:
// Keep room occupancy status private, changing it only via methods like checkIn(const std::string& gName) and checkOut().
// Hide pricing details inside the room classes.
// Use constructors and destructors to:
// Display messages when reservations are created and destroyed, simulating allocation and release of booking resources.
// The system should allow a tester to:
// Create rooms of various types.
// Create reservations.
// Attempt to book an already occupied room and see that it is prevented by internal logic (not by manipulating fields directly).
#include <iostream>
#include <string>

class Room {
protected:
    int roomNumber;
    double basePrice;
    bool occupied;
    std::string guestName;
public:
    Room(int num, double price)
        : roomNumber(num), basePrice(price),
          occupied(false), guestName("") {}

    bool isOccupied() const { return occupied; }
    int getRoomNumber() const { return roomNumber; }
    double getBasePrice() const { return basePrice; }
    std::string getGuestName() const { return guestName; }

    bool checkIn(const std::string& gName) {
        if (occupied) return false;
        occupied = true;
        guestName = gName;
        return true;
    }

    void checkOut() {
        occupied = false;
        guestName = "";
    }
};

class StandardRoom : public Room {
public:
    StandardRoom(int num)
        : Room(num, 3000) {}
};

class DeluxeRoom : public Room {
public:
    DeluxeRoom(int num)
        : Room(num, 5000) {}
    double calculatePrice(int nights) const {
        return basePrice * nights * 1.1;
    }
};

class SuiteRoom : public Room {
public:
    SuiteRoom(int num)
        : Room(num, 8000) {}
    double calculatePrice(int nights) const {
        return basePrice * nights * 1.3;
    }
};

class Reservation {
    Room& room;
    int nights;
    double totalCost;
    std::string guestName;
public:
    Reservation(Room& r, const std::string& guest, int n)
        : room(r), nights(n), totalCost(0), guestName(guest) {
        if (room.isOccupied()) {
            std::cout << "Cannot create reservation, room already occupied\n";
            return;
        }
        room.checkIn(guestName);
        totalCost = room.getBasePrice() * nights;
        std::cout << "Reservation created for "
                  << guestName
                  << " in room " << room.getRoomNumber()
                  << ", total cost: " << totalCost << "\n";
    }

    ~Reservation() {
        room.checkOut();
        std::cout << "Reservation ended for "
                  << guestName << "\n";
    }
};

int main() {
    StandardRoom sr(101);
    SuiteRoom su(201);

    Reservation r1(sr, "Ali", 3);
    return 0;
}