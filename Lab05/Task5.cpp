#include <iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
};

class Teacher : virtual public Person {
public:
    string subject;
};

class Student : virtual public Person {
public:
    int studentID;
};

class TeachingAssistant : public Teacher, public Student {
public:
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main() {
    TeachingAssistant ta;
    ta.name = "Ali";
    ta.age = 24;
    ta.studentID = 101;
    ta.subject = "OOP";
    ta.display();
    return 0;
}
