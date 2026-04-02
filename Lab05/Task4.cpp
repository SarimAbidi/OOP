#include <iostream>
using namespace std;

class Device {
protected:
    string deviceName;
    string brand;

public:
    void setDevice(string d, string b) {
        deviceName = d;
        brand = b;
    }
};

class Connectivity {
protected:
    bool wifiStatus;
    bool bluetoothStatus;

public:
    void setConnectivity(bool w, bool b) {
        wifiStatus = w;
        bluetoothStatus = b;
    }
};

class SmartWatch : public Device, public Connectivity {
private:
    int heartRate;
    int stepCount;

public:
    void setSmartWatch(int hr, int steps) {
        heartRate = hr;
        stepCount = steps;
    }

    void display() {
        cout << "Device: " << deviceName << endl;
        cout << "Brand: " << brand << endl;
        cout << "WiFi: " << (wifiStatus ? "On" : "Off") << endl;
        cout << "Bluetooth: " << (bluetoothStatus ? "On" : "Off") << endl;
        cout << "Heart Rate: " << heartRate << endl;
        cout << "Steps: " << stepCount << endl;
    }
};

int main() {
    SmartWatch s;
    s.setDevice("Smart Watch", "Apple");
    s.setConnectivity(true, true);
    s.setSmartWatch(72, 5000);
    s.display();
    return 0;
}
