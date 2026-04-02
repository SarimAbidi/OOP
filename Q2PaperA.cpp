#include <iostream>
#include <string>
using namespace std;

class Light {
public:
    int brightness;
    int power;

    Light(int b = 0, int p = 0) {
        brightness = b;
        power = p;
    }
};

class AirConditioner {
public:
    float tonnage;
    int power;

    AirConditioner(float t = 0, int p = 0) {
        tonnage = t;
        power = p;
    }
};

class SecurityCamera {
public:
    string resolution;
    int power;

    SecurityCamera(string r = "", int p = 0) {
        resolution = r;
        power = p;
    }
};

class House {
    string name;
    int controllerID;
    Light lights[5];
    AirConditioner acs[3];
    SecurityCamera cameras[4];
    int lightCount;
    int acCount;
    int cameraCount;

public:
    House(string n, int id) {
        name = n;
        controllerID = id;
        lightCount = 0;
        acCount = 0;
        cameraCount = 0;
    }

    void addLight(Light l) {
        if (lightCount < 5) {
            lights[lightCount] = l;
            lightCount++;
        }
    }

    void addAC(AirConditioner a) {
        if (acCount < 3) {
            acs[acCount] = a;
            acCount++;
        }
    }

    void addCamera(SecurityCamera c) {
        if (cameraCount < 4) {
            cameras[cameraCount] = c;
            cameraCount++;
        }
    }

    int calculateTotalPower() {
        int total = 0;

        for (int i = 0; i < lightCount; i++)
            total += lights[i].power;

        for (int i = 0; i < acCount; i++)
            total += acs[i].power;

        for (int i = 0; i < cameraCount; i++)
            total += cameras[i].power;

        return total;
    }

    void display() {
        cout << "House: " << name << endl;
        cout << "Controller ID: CTRL-" << controllerID << endl;

        cout << endl;
        cout << "Lights:" << endl;
        for (int i = 0; i < lightCount; i++) {
            cout << "Light " << i + 1 << " -> Brightness: " << lights[i].brightness
                 << " lumens, Power: " << lights[i].power << "W" << endl;
        }

        cout << endl;
        cout << "Air Conditioners:" << endl;
        for (int i = 0; i < acCount; i++) {
            cout << "AC " << i + 1 << " -> Tonnage: " << acs[i].tonnage
                 << " Ton, Power: " << acs[i].power << "W" << endl;
        }

        cout << endl;
        cout << "Security Cameras:" << endl;
        for (int i = 0; i < cameraCount; i++) {
            cout << "Camera " << i + 1 << " -> Resolution: " << cameras[i].resolution
                 << ", Power: " << cameras[i].power << "W" << endl;
        }

        cout << endl;
        cout << "Total Lights: " << lightCount << endl;
        cout << "Total ACs: " << acCount << endl;
        cout << "Total Cameras: " << cameraCount << endl;
        cout << "Total Power Consumption: " << calculateTotalPower() << "W" << endl;
    }
};

int main() {
    House h("Smart Villa", 1001);

    h.addLight(Light(800, 10));
    h.addLight(Light(600, 8));

    h.addAC(AirConditioner(1.5, 1500));
    h.addAC(AirConditioner(2.0, 2000));

    h.addCamera(SecurityCamera("1080p", 15));
    h.addCamera(SecurityCamera("4K", 10));

    h.display();

    return 0;
}
