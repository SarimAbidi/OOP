#include <iostream>
using namespace std;

class Author {
public:
    string name;
    int authorID;

    Author(string n, int id) {
        name = n;
        authorID = id;
    }
};

class Book {
private:
    string title;
    Author* authors[5];
    int authorCount;

public:
    Book(string t) {
        title = t;
        authorCount = 0;
    }

    void addAuthor(Author* a) {
        authors[authorCount++] = a;
    }

    void displayAuthors() {
        cout << "Book: " << title << endl;
        cout << "Authors:\n";
        for(int i=0;i<authorCount;i++) {
            cout << authors[i]->name << " (ID: " << authors[i]->authorID << ")" << endl;
        }
    }
};

int main() {
    Author a1("Ali",101);
    Author a2("Sara",102);

    Book b1("OOP Concepts");

    b1.addAuthor(&a1);
    b1.addAuthor(&a2);

    b1.displayAuthors();

    return 0;
}
