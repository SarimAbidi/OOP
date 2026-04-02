#include <iostream>
using namespace std;

class University {
private:
    static int totalStudents;
    string universityName;

public:
    University(string name) {
        universityName = name;
        totalStudents++;
    }

    static int getTotalStudents() {
        return totalStudents;
    }

    void displayInfo() {
        cout << "University Name: " << universityName << endl;
        cout << "Total Students: " << totalStudents << endl;
    }
};

int University::totalStudents = 0;

int main() {
    University u1("NED University");
    University u2("FAST University");
    University u3("IBA Karachi");

    u1.displayInfo();
    u2.displayInfo();
    u3.displayInfo();

    cout << "\nAccess using class name: ";
    cout << University::getTotalStudents() << endl;

    return 0;
}
