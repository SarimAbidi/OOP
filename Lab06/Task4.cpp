#include <iostream>
using namespace std;

class Account {
public:
    virtual float calculateInterest(float amount) {
        return 0;
    }
};

class SavingsAccount : public Account {
public:
    float calculateInterest(float amount) override {
        return amount * 0.05;
    }
};

class CurrentAccount : public Account {
public:
    float calculateInterest(float amount) override {
        return amount * 0.02;
    }
};

int main() {
    Account* acc;
    SavingsAccount s;
    CurrentAccount c;

    acc = &s;
    cout << "Savings Interest: " << acc->calculateInterest(10000) << endl;

    acc = &c;
    cout << "Current Interest: " << acc->calculateInterest(10000) << endl;

    return 0;
}
