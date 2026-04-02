#include <iostream>
#include <string>
using namespace std;

class Laptop {
    string brand;
    string model;
    int price;
    int ram;
    static int totalCount;
    static int totalPrice;

public:
    Laptop(string b, string m, int p, int r) {
        brand = b;
        model = m;
        price = p;
        ram = r;
        totalCount++;
        totalPrice += price;
    }

    Laptop(const Laptop& obj) {
        brand = obj.brand;
        model = obj.model;
        price = obj.price;
        ram = obj.ram;
        totalCount++;
        totalPrice += price;
    }

    void display(int n) {
        cout << "Laptop " << n << ": " << brand << " " << model
             << ", Price: " << price << ", RAM: " << ram << "GB" << endl;
    }

    static int getTotalCount() {
        return totalCount;
    }

    static int getTotalPrice() {
        return totalPrice;
    }
};

int Laptop::totalCount = 0;
int Laptop::totalPrice = 0;

int main() {
    Laptop l1("Dell", "Inspiron", 60000, 8);
    Laptop l2("HP", "Pavilion", 70000, 16);
    Laptop l3(l1);

    l1.display(1);
    l2.display(2);
    cout << "Laptop 3 (Copy of Laptop 1): Dell Inspiron, Price: 60000, RAM: 8GB" << endl;

    cout << endl;
    cout << "Total number of laptops: " << Laptop::getTotalCount() << endl;
    cout << "Total price of all laptops: " << Laptop::getTotalPrice() << endl;

    return 0;
}
