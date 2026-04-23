#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int studentID;
    int age;

public:
    // 1. init()
    void init(string n, int id, int a) {
        name = n;
        studentID = id;
        age = a;
    }

    // 2. printStudentInfo()
    void printStudentInfo() {
        cout << "Name: " << name 
             << ", ID: " << studentID 
             << ", Age: " << age << endl;
    }

    // 3. getID()
    int getID() {
        return studentID;
    }

    // 4. getAge()
    int getAge() {
        return age;
    }

    // 5. getName()
    string getName() {
        return name;
    }

    // Allow swap function to access private members
    friend void personSwap(Person &p1, Person &p2);
};

// 6. personSwap(...)
void personSwap(Person &p1, Person &p2) {
    // Temporary variables
    string tempName = p1.name;
    int tempID = p1.studentID;
    int tempAge = p1.age;

    // Swap values
    p1.name = p2.name;
    p1.studentID = p2.studentID;
    p1.age = p2.age;

    p2.name = tempName;
    p2.studentID = tempID;
    p2.age = tempAge;
}

// Example usage
int main() {
    Person p1, p2;

    p1.init("Alice", 2026312345, 20);
    p2.init("Bob", 2019354321, 25);

    cout << "Before Swap:" << endl;
    p1.printStudentInfo();
    p2.printStudentInfo();

    personSwap(p1, p2);

    cout << "\nAfter Swap:" << endl;
    p1.printStudentInfo();
    p2.printStudentInfo();

    return 0;
}