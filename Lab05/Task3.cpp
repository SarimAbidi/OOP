#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    int studentID;
    string program;

public:
    Student(string n, int a, int id, string p)
        : Person(n, a) {
        studentID = id;
        program = p;
    }

    void displayStudent() {
        displayPerson();
        cout << "Student ID: " << studentID << endl;
        cout << "Program: " << program << endl;
    }
};

class GraduateStudent : public Student {
private:
    string researchTopic;
    string supervisorName;

public:
    GraduateStudent(string n, int a, int id, string p, string topic, string supervisor)
        : Student(n, a, id, p) {
        researchTopic = topic;
        supervisorName = supervisor;
    }

    void displayGraduateStudent() {
        displayStudent();
        cout << "Research Topic: " << researchTopic << endl;
        cout << "Supervisor: " << supervisorName << endl;
    }
};

int main() {
    GraduateStudent g("Ali", 25, 101, "CS", "AI", "Dr. Khan");
    g.displayGraduateStudent();
    return 0;
}
