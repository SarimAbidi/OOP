#include <iostream>
using namespace std;

class Payment {
public:
    void pay(int amount) {
        cout << "Paid Rs." << amount << " via Cash\n";
    }

    void pay(int amount, string cardNumber) {
        cout << "Paid Rs." << amount << " via Card\n";
        cout << "Card Number: " << cardNumber << endl;
    }

    void pay(int amount, string bank, string accountNo) {
        cout << "Paid Rs." << amount << " via Online Transfer\n";
        cout << "Bank: " << bank << " Account No: " << accountNo << endl;
    }
};

int main() {
    Payment p;
    p.pay(500);
    p.pay(1000, "1234-5678-9012");
    p.pay(2000, "HBL", "987654321");
    return 0;
}
