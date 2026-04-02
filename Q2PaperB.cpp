#include <iostream>
#include <string>
using namespace std;

class HeartMonitor {
public:
    int heartRate;

    HeartMonitor(int h = 0) {
        heartRate = h;
    }
};

class BPMonitor {
public:
    int systolic;
    int diastolic;

    BPMonitor(int s = 0, int d = 0) {
        systolic = s;
        diastolic = d;
    }
};

class OxygenSensor {
public:
    int oxygenLevel;

    OxygenSensor(int o = 0) {
        oxygenLevel = o;
    }
};

class Patient {
    string name;
    int patientID;
    HeartMonitor heartMonitors[2];
    BPMonitor bpMonitors[2];
    OxygenSensor oxygenSensors[3];
    int heartCount;
    int bpCount;
    int oxygenCount;

public:
    Patient(string n, int id) {
        name = n;
        patientID = id;
        heartCount = 0;
        bpCount = 0;
        oxygenCount = 0;
    }

    void addHeartMonitor(HeartMonitor h) {
        if (heartCount < 2) {
            heartMonitors[heartCount] = h;
            heartCount++;
        }
    }

    void addBPMonitor(BPMonitor b) {
        if (bpCount < 2) {
            bpMonitors[bpCount] = b;
            bpCount++;
        }
    }

    void addOxygenSensor(OxygenSensor o) {
        if (oxygenCount < 3) {
            oxygenSensors[oxygenCount] = o;
            oxygenCount++;
        }
    }

    double calculateRiskScore() {
        double score = 0;

        for (int i = 0; i < heartCount; i++) {
            if (heartMonitors[i].heartRate > 100 || heartMonitors[i].heartRate < 60)
                score += 1.5;
            else
                score += 1.0;
        }

        for (int i = 0; i < bpCount; i++) {
            if (bpMonitors[i].systolic > 130 || bpMonitors[i].diastolic > 85)
                score += 2.0;
            else
                score += 1.0;
        }

        for (int i = 0; i < oxygenCount; i++) {
            if (oxygenSensors[i].oxygenLevel < 95)
                score += 1.0;
            else
                score += 0.5;
        }

        return score;
    }

    void display() {
        cout << "Patient: " << name << ", Patient ID: " << patientID << endl;
        cout << endl;

        for (int i = 0; i < heartCount; i++) {
            cout << "Heart Monitor " << i + 1 << ": Heart Rate: "
                 << heartMonitors[i].heartRate << " bpm" << endl;
        }

        cout << endl;
        for (int i = 0; i < bpCount; i++) {
            cout << "BP Monitor " << i + 1 << ": Systolic: "
                 << bpMonitors[i].systolic << " mmHg, Diastolic: "
                 << bpMonitors[i].diastolic << " mmHg" << endl;
        }

        cout << endl;
        for (int i = 0; i < oxygenCount; i++) {
            cout << "Oxygen Sensor " << i + 1 << ": Oxygen Level: "
                 << oxygenSensors[i].oxygenLevel << "%" << endl;
        }

        cout << endl;
        cout << "Total number of Heart Monitors: " << heartCount << endl;
        cout << "Total number of BP Monitors: " << bpCount << endl;
        cout << "Total number of Oxygen Sensors: " << oxygenCount << endl;

        cout << endl;
        cout << "Overall Health Risk Score: " << calculateRiskScore() << endl;
    }
};

int main() {
    Patient p("Ali Khan", 101);

    p.addHeartMonitor(HeartMonitor(78));
    p.addHeartMonitor(HeartMonitor(92));

    p.addBPMonitor(BPMonitor(120, 80));
    p.addBPMonitor(BPMonitor(140, 90));

    p.addOxygenSensor(OxygenSensor(98));
    p.addOxygenSensor(OxygenSensor(95));
    p.addOxygenSensor(OxygenSensor(92));

    p.display();

    return 0;
}
