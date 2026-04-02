#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int* marks;

public:
    Student(string n, int m) {
        name = n;
        marks = new int;
        *marks = m;
    }

    Student(const Student& s) {
        name = s.name;
        marks = new int;
        *marks = *(s.marks);
    }

    void setMarks(int m) {
        *marks = m;
    }

    void show() {
        cout << "Name: " << name << endl;
        cout << "Marks: " << *marks << endl;
        cout << "------------------" << endl;
    }

    ~Student() {
        delete marks;
    }
};

int main() {
    Student s1("Ali", 90);

    Student s2 = s1;   

    s2.setMarks(50);   

    cout << "Original Student:" << endl;
    s1.show();

    cout << "Copied Student:" << endl;
    s2.show();

    return 0;
}