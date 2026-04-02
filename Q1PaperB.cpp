#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int rollNo;
    int* marks;
    static int totalStudents;
    static int totalMarks;

public:
    Student(string n, int r, int m1, int m2, int m3) {
        name = n;
        rollNo = r;
        marks = new int[3];
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        totalStudents++;
        totalMarks += m1 + m2 + m3;
    }

    Student(const Student& s) {
        name = s.name;
        rollNo = s.rollNo;
        marks = new int[3];
        for (int i = 0; i < 3; i++) {
            marks[i] = s.marks[i];
        }
        totalStudents++;
        totalMarks += marks[0] + marks[1] + marks[2];
    }

    void setMark(int index, int value) {
        totalMarks -= marks[index];
        marks[index] = value;
        totalMarks += marks[index];
    }

    void display(int n, bool isCopy = false) {
        if (isCopy)
            cout << "Student " << n << " (Deep Copy of Student 1): ";
        else
            cout << "Student " << n << ": ";

        cout << name << ", Roll No: " << rollNo << ", Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    static int getTotalStudents() {
        return totalStudents;
    }

    static int getTotalMarks() {
        return totalMarks;
    }

    ~Student() {
        delete[] marks;
    }
};

int Student::totalStudents = 0;
int Student::totalMarks = 0;

int main() {
    Student s1("Alice", 1, 85, 90, 80);
    Student s2("Bob", 2, 75, 70, 65);
    Student s3(s1);

    s3.setMark(0, 95);

    s1.display(1);
    s2.display(2);
    s3.display(3, true);

    cout << endl;
    cout << "Total number of students: " << Student::getTotalStudents() << endl;
    cout << "Total marks of all students: " << Student::getTotalMarks() << endl;

    return 0;
}
