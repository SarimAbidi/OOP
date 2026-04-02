#include <iostream>
using namespace std;

class Student {
private:
    static int counter;
    int id;
    string name;
    int marks[5];

public:
    Student() {
        counter++;
        id = counter;
    }

    void inputData() {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter marks of 5 subjects:\n";
        for(int i=0;i<5;i++) {
            cin >> marks[i];
        }
    }

    float calculateAverage() {
        int sum = 0;
        for(int i=0;i<5;i++) {
            sum += marks[i];
        }
        return sum/5.0;
    }

    void display() {
        cout << "ID: " << id
             << " Name: " << name
             << " Average: " << calculateAverage()
             << endl;
    }

    float getAverage() {
        return calculateAverage();
    }
};

int Student::counter = 0;

int main() {

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[100];

    for(int i=0;i<n;i++) {
        cout << "\nStudent " << i+1 << endl;
        s[i].inputData();
    }

    cout << "\nStudent Records\n";
    for(int i=0;i<n;i++) {
        s[i].display();
    }

    int top = 0;

    for(int i=1;i<n;i++) {
        if(s[i].getAverage() > s[top].getAverage()) {
            top = i;
        }
    }

    cout << "\nTop Student:\n";
    s[top].display();

    return 0;
}
