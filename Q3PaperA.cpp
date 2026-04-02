#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string vehicleID;
    string brand;
    int capacity;

public:
    Vehicle(string id, string b, int c) {
        vehicleID = id;
        brand = b;
        capacity = c;
    }

    virtual void display() {
        cout << "Brand: " << brand << ", Capacity: " << capacity << "kg";
    }

    string getID() {
        return vehicleID;
    }

    virtual string getType() {
        return "Vehicle";
    }
};

class Truck : public Vehicle {
protected:
    int loadCapacity;

public:
    Truck(string id, string b, int c, int l) : Vehicle(id, b, c) {
        loadCapacity = l;
    }

    void display() {
        cout << "Brand: " << brand << ", Capacity: " << capacity
             << "kg, Load Capacity: " << loadCapacity << "kg";
    }

    string getType() {
        return "Truck";
    }
};

class Van : public Vehicle {
    int passengerCapacity;

public:
    Van(string id, string b, int c, int p) : Vehicle(id, b, c) {
        passengerCapacity = p;
    }

    void display() {
        cout << "Brand: " << brand << ", Capacity: " << capacity
             << "kg, Passenger Capacity: " << passengerCapacity;
    }

    string getType() {
        return "Van";
    }
};

class Bike : public Vehicle {
    int fuelEfficiency;

public:
    Bike(string id, string b, int c, int f) : Vehicle(id, b, c) {
        fuelEfficiency = f;
    }

    void display() {
        cout << "Brand: " << brand << ", Capacity: " << capacity
             << "kg, Fuel Efficiency: " << fuelEfficiency << " km/l";
    }

    string getType() {
        return "Bike";
    }
};

class RefrigeratedTruck : public Truck {
    int temperature;

public:
    RefrigeratedTruck(string id, string b, int c, int l, int t) : Truck(id, b, c, l) {
        temperature = t;
    }

    void display() {
        cout << "Brand: " << brand << ", Capacity: " << capacity
             << "kg, Load Capacity: " << loadCapacity << "kg, Temp: "
             << temperature << "C";
    }

    string getType() {
        return "Refrigerated Truck";
    }
};

class Driver {
protected:
    string name;
    string licenseType;

public:
    Driver(string n, string l) {
        name = n;
        licenseType = l;
    }

    string getName() {
        return name;
    }

    string getLicense() {
        return licenseType;
    }
};

class DeliveryAgent : public Driver {
    Vehicle* assignedVehicle;

public:
    DeliveryAgent(string n, string l) : Driver(n, l) {
        assignedVehicle = NULL;
    }

    void assignVehicle(Vehicle* v) {
        assignedVehicle = v;
    }

    void display() {
        cout << name << " (" << licenseType << ") -> "
             << assignedVehicle->getType() << " (" << assignedVehicle->getID() << ")" << endl;
    }
};

int main() {
    Truck t("T101", "Volvo", 10000, 12000);
    Van v("V202", "Toyota", 2000, 8);
    Bike b("B303", "Honda", 150, 45);
    RefrigeratedTruck rt("RT404", "Mercedes", 8000, 9000, -5);

    DeliveryAgent d1("Ali Khan", "Heavy License");
    DeliveryAgent d2("Sara Ahmed", "Light License");
    DeliveryAgent d3("Usman Ali", "Bike License");
    DeliveryAgent d4("Ahmed Raza", "Heavy License");

    d1.assignVehicle(&t);
    d2.assignVehicle(&v);
    d3.assignVehicle(&b);
    d4.assignVehicle(&rt);

    cout << "Transportation System:" << endl;
    cout << endl;

    cout << "Vehicle: Truck (" << t.getID() << ")" << endl;
    t.display();
    cout << endl << endl;

    cout << "Vehicle: Van (" << v.getID() << ")" << endl;
    v.display();
    cout << endl << endl;

    cout << "Vehicle: Bike (" << b.getID() << ")" << endl;
    b.display();
    cout << endl << endl;

    cout << "Vehicle: Refrigerated Truck (" << rt.getID() << ")" << endl;
    rt.display();
    cout << endl << endl;

    cout << "Delivery Agents:" << endl;
    d1.display();
    d2.display();
    d3.display();
    d4.display();

    cout << endl;
    cout << "Total Vehicles: 4" << endl;
    cout << "Total Delivery Agents: 4" << endl;

    return 0;
}
