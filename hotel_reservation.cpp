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
