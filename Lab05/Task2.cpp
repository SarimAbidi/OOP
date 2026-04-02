#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    void setPerson(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << " Age: " << age << endl;
    }
};

class StudentPublic : public Person {
public:
    void show() {
        cout << "Public Inheritance:\n";
        displayPerson();
    }
};

class StudentProtected : protected Person {
public:
    void show() {
        cout << "Protected Inheritance:\n";
        displayPerson();
    }
};

class StudentPrivate : private Person {
public:
    void show() {
        cout << "Private Inheritance:\n";
        displayPerson();
    }
};

int main() {
    StudentPublic s1;
    s1.setPerson("Ali", 20);
    s1.show();

    StudentProtected s2;
    s2.setPerson("Sara", 21);
    s2.show();

    StudentPrivate s3;
    s3.setPerson("Ahmed", 22);
    s3.show();

    return 0;
}
