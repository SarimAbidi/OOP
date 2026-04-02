#include <iostream>
using namespace std;

class Book {
private:
    const string ISBN;
    string title;

public:
    Book(string isbn, string t) : ISBN(isbn) {
        title = t;
    }

    void updateTitle(string newTitle) {
        title = newTitle;
    }

    void displayDetails() const {
        cout << "ISBN: " << ISBN << endl;
        cout << "Title: " << title << endl;
    }
};

int main() {
    Book b1("97812345", "C++ Programming");
    b1.displayDetails();

    b1.updateTitle("Advanced C++");
    cout << "\nAfter Updating Title\n";
    b1.displayDetails();

    const Book b2("11122233", "Data Structures");
    cout << "\nConst Book Object\n";
    b2.displayDetails();

    return 0;
}
