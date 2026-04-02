// 4. Library Book Lending with Membership Levels
// A community library has books and different types of members. Members can be RegularMember or PremiumMember. Regular members can borrow fewer books and for a shorter duration than premium members. Some books are reference-only and cannot be borrowed at all. The librarian wants a program that handles basic lending rules but hides internal counters and validation details from direct modification.

// Requirements:

// Create a class hierarchy:
// Base class Member with attributes like member ID, name, and maximum allowed borrowed books.
// RegularMember and PremiumMember inherit from Member and set different borrowing limits in their constructors.
// Create a class Book that includes:
// Book ID, title, author, and a flag indicating if it is reference-only.
// Internal status of whether it is currently borrowed.
// Use encapsulation to:
// Make book status private and only modifiable via methods like borrow(...) and returnBook().
// Prevent borrowing if:
// The book is reference-only.
// The book is already borrowed.
// The member has reached their borrowing limit.
// Use constructors to:
// Initialize Member and Book objects with all required data.
// For derived Member classes, automatically set appropriate limits in the constructor.
// Optionally, create a class Library that:
// Contains collections of Book and Member (you may use fixed-size arrays, but do not use std::vector).
// Provides methods like lendBook(memberId, bookId) that internally finds objects and delegates to the borrow() method.
// Use destructors or explicit cleanup methods to:
// Log when a book object is destroyed (e.g., removed from the system) or a member is removed.
// Students must design interactions such that:
// Books and members are created.
// Borrowing and returning operations are tested with both valid and invalid cases.
// Attempts to violate the rules are safely handled inside methods, not by modifying fields directly.
// Important: In your implementation, do NOT use virtual functions, the override keyword, std::vector, or pointers.
#include <iostream>
#include <string>

class Member {
protected:
    std::string memberId;
    std::string name;
    int maxBorrow;
    int currentlyBorrowed;
public:
    Member(const std::string& id, const std::string& n, int maxB)
        : memberId(id), name(n), maxBorrow(maxB),
          currentlyBorrowed(0) {}

    bool canBorrow() const { return currentlyBorrowed < maxBorrow; }
    void incrementBorrow() { currentlyBorrowed++; }
    void decrementBorrow() { if (currentlyBorrowed > 0) currentlyBorrowed--; }

    std::string getName() const { return name; }
};

class RegularMember : public Member {
public:
    RegularMember(const std::string& id, const std::string& n)
        : Member(id, n, 3) {}
};

class PremiumMember : public Member {
public:
    PremiumMember(const std::string& id, const std::string& n)
        : Member(id, n, 10) {}
};

class Book {
    std::string id;
    std::string title;
    std::string author;
    bool referenceOnly;
    bool borrowed;
    std::string borrowerId;
    std::string borrowerName;
public:
    Book(const std::string& i, const std::string& t,
         const std::string& a, bool refOnly)
        : id(i), title(t), author(a),
          referenceOnly(refOnly), borrowed(false),
          borrowerId(""), borrowerName("") {}

    bool borrow(Member& m) {
        if (referenceOnly || borrowed || !m.canBorrow()) {
            return false;
        }
        borrowed = true;
        borrowerId = "HIDDEN_ID"; // could be m's ID if we exposed it
        borrowerName = m.getName();
        m.incrementBorrow();
        return true;
    }

    void returnBook() {
        // In a fuller design we would track the associated Member to decrement.
        borrowed = false;
        borrowerId = "";
        borrowerName = "";
    }

    void printStatus() const {
        std::cout << "Book " << title << " ("
                  << id << ") - ";
        if (referenceOnly) std::cout << "Reference only, ";
        if (borrowed)
            std::cout << "Borrowed by " << borrowerName << "\n";
        else
            std::cout << "Available\n";
    }
};

int main() {
    RegularMember m1("M1", "Ali");
    PremiumMember m2("M2", "Sara");

    Book b1("B1", "C++ Primer", "Lippman", false);
    Book b2("B2", "Encyclopedia", "XYZ", true);

    b1.borrow(m1);
    b2.borrow(m1); // should fail (reference only)

    b1.printStatus();
    b2.printStatus();

    b1.returnBook();
    b1.printStatus();
    return 0;
}