#include <iostream>
using namespace std;

class Employee {
public:
    virtual float calculateSalary() {
        return 0;
    }
};

class Manager : public Employee {
public:
    float calculateSalary() override {
        return 50000 + 10000;
    }
};

class Developer : public Employee {
public:
    float calculateSalary() override {
        return 40000 + 5000;
    }
};

int main() {
    Employee* e;
    Manager m;
    Developer d;

    e = &m;
    cout << "Manager Salary: " << e->calculateSalary() << endl;

    e = &d;
    cout << "Developer Salary: " << e->calculateSalary() << endl;

    return 0;
}
