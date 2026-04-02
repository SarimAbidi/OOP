#include <iostream>
using namespace std;

class Car {
private:
    string model;
    int year;
    int mileage;

public:
    Car(string model, int year, int mileage) {
        this->model = model;
        this->year = year;
        this->mileage = mileage;
    }

    void updateMileage(int mileage) {
        this->mileage += mileage;
    }

    void display() {
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Mileage: " << mileage << endl;
        cout << "------------------" << endl;
    }
};

int main() {
    Car c1("Honda", 2022, 10000);

    cout << "Before Update:" << endl;
    c1.display();

    c1.updateMileage(500);

    cout << "After Update:" << endl;
    c1.display();

    return 0;
}