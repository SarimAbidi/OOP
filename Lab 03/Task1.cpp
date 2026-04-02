#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

public:
    Book() {
        title = "Not Available";
        author = "Unknown";
        price = 0;
    }

    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "------------------" << endl;
    }
};

int main() {
    Book b1;
    Book b2("C++ Basics", "John", 500); 
    b1.display();
    b2.display();

    return 0;
}