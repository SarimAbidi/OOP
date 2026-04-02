#include <iostream>
using namespace std;

class Processor {
public:
    string model;
    double speed;

    Processor(string m="Unknown", double s=0) {
        model = m;
        speed = s;
    }
};

class RAM {
public:
    int size;
    string type;

    RAM(int s=0, string t="Unknown") {
        size = s;
        type = t;
    }
};

class Computer {
private:
    Processor processor;
    RAM ram;

public:
    Computer(string model, double speed, int size, string type)
        : processor(model, speed), ram(size, type) {}

    void displaySpecs() {
        cout << "Processor Model: " << processor.model << endl;
        cout << "Processor Speed: " << processor.speed << " GHz" << endl;
        cout << "RAM Size: " << ram.size << " GB" << endl;
        cout << "RAM Type: " << ram.type << endl;
    }
};

int main() {
    Computer c1("Intel i7",3.5,16,"DDR4");
    c1.displaySpecs();
    return 0;
}
