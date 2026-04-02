#include <iostream>
using namespace std;

class Employee {
private:
    int empID;
    string name;
    float salary;

public:
    void setEmployeeData(int id, string n, float s) {
        empID = id;
        name = n;
        salary = s;
    }

    void displayEmployeeData() {
        cout << "Employee ID: " << empID << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee {
private:
    string department;
    float bonus;

public:
    void setManagerData(string dept, float b) {
        department = dept;
        bonus = b;
    }

    void displayManagerData() {
        displayEmployeeData();
        cout << "Department: " << department << endl;
        cout << "Bonus: " << bonus << endl;
    }
};

int main() {
    Manager m;
    m.setEmployeeData(101, "Ali", 50000);
    m.setManagerData("IT", 10000);
    m.displayManagerData();
    return 0;
}
