#include <iostream>
using namespace std;

class Shape {
public:
    float area(float radius) {
        return 3.14 * radius * radius;
    }

    float area(float length, float width) {
        return length * width;
    }

    float area(float base, float height, bool isTriangle) {
        return 0.5 * base * height;
    }
};

int main() {
    Shape s;
    cout << "Circle Area: " << s.area(5) << endl;
    cout << "Rectangle Area: " << s.area(4, 6) << endl;
    cout << "Triangle Area: " << s.area(3, 7, true) << endl;
    return 0;
}
