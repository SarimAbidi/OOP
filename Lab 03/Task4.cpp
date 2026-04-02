#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;
    const double area;

public:
    Rectangle(double l, double w)
        : length(l), width(w), area(l * w) {
    }

    void show() {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << area << endl;
        cout << "------------------" << endl;
    }

    void setLength(double l) {
        length = l;
    }

    void setWidth(double w) {
        width = w;
    }
};

int main() {
    Rectangle r1(4, 5);

    cout << "Before Change:" << endl;
    r1.show();

    r1.setLength(10);
    r1.setWidth(8);

    cout << "After Change:" << endl;
    r1.show();

    return 0;
}