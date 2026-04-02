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
