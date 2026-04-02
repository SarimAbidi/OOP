#include <iostream>
#include <string>

class Course {
protected:
    std::string id;
    std::string title;
    std::string instructor;
    double baseFee;
    int enrolledCount;
public:
    Course(const std::string& i, const std::string& t,
           const std::string& ins, double fee)
        : id(i), title(t), instructor(ins),
          baseFee(fee), enrolledCount(0) {}

    std::string getId() const { return id; }
    double calculateFinalFee() const { return baseFee; }
    void printBasicDetails() const {
        std::cout << "Course: " << title << " (" << id << ")\n";
    }

    void incrementEnrollment() { enrolledCount++; }
    int getEnrolledCount() const { return enrolledCount; }
};

class RecordedCourse : public Course {
    int videoCount;
public:
    RecordedCourse(const std::string& i, const std::string& t,
                   const std::string& ins, double fee, int vids)
        : Course(i, t, ins, fee), videoCount(vids) {}

    void printDetails() const {
        printBasicDetails();
        std::cout << "Recorded videos: " << videoCount << "\n";
    }
};

class LiveCourse : public Course {
    std::string schedule;
    int sessions;
public:
    LiveCourse(const std::string& i, const std::string& t,
               const std::string& ins, double fee,
               const std::string& sched, int sess)
        : Course(i, t, ins, fee),
          schedule(sched), sessions(sess) {}

    double calculateFinalFee() const {
        return baseFee + 200; // example extra cost
    }

    void printDetails() const {
        printBasicDetails();
        std::cout << "Live schedule: " << schedule
                  << ", sessions: " << sessions << "\n";
    }
};

class HybridCourse : public Course {
    int videoCount;
    int liveSessions;
public:
    HybridCourse(const std::string& i, const std::string& t,
                 const std::string& ins, double fee,
                 int vids, int sess)
        : Course(i, t, ins, fee),
          videoCount(vids), liveSessions(sess) {}

    double calculateFinalFee() const {
        return baseFee + 150;
    }

    void printDetails() const {
        printBasicDetails();
        std::cout << "Hybrid: " << videoCount
                  << " videos, " << liveSessions
                  << " live sessions\n";
    }
};

class Student {
    std::string id;
    std::string name;
    static const int MAX_COURSES = 5;
    std::string enrolledCourseIds[MAX_COURSES];
    int enrolledCount;
public:
    Student(const std::string& i, const std::string& n)
        : id(i), name(n), enrolledCount(0) {}

    void enrollInCourse(Course& c) {
        if (enrolledCount >= MAX_COURSES) return;
        enrolledCourseIds[enrolledCount] = c.getId();
        enrolledCount++;
        c.incrementEnrollment();
    }

    void printInfo() const {
        std::cout << "Student " << name << " (" << id << ")\n";
        std::cout << "Enrolled in " << enrolledCount << " course(s):\n";
        for (int i = 0; i < enrolledCount; ++i) {
            std::cout << "- " << enrolledCourseIds[i] << "\n";
        }
    }
};

int main() {
    RecordedCourse rc("R101", "C++ Basics", "Ali", 1000, 20);
    LiveCourse lc("L201", "OOP Live", "Sara", 1500, "MWF 5-7", 10);
    HybridCourse hc("H301", "Data Structures", "Ahmed", 2000, 15, 6);

    Student s1("S1", "Hassan");
    s1.enrollInCourse(rc);
    s1.enrollInCourse(hc);

    s1.printInfo();

    std::cout << "Enroll count Data Structures: "
              << hc.getEnrolledCount() << "\n";
    return 0;
}
