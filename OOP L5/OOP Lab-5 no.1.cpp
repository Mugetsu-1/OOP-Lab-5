#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Fmachine {
public:
    virtual void getdata() = 0; // Pure virtual function
    virtual void putdata() = 0; // Pure virtual function
    virtual ~Fmachine() {} // Virtual destructor
};

// Derived class
class Aeroplane : public Fmachine {
private:
    string code;
    string name;
    int capacity;
public:
    void getdata() override {
        cout << "Enter code: ";
        cin >> code;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter capacity: ";
        cin >> capacity;
    }

    void putdata() override {
        cout << "Code: " << code << endl;
        cout << "Name: " << name << endl;
        cout << "Capacity: " << capacity << endl;
    }
};

int main() {
    Fmachine* ptr = new Aeroplane(); // Dynamic memory allocation
    ptr->getdata(); // Dynamic binding
    ptr->putdata(); // Dynamic binding
    delete ptr; // Freeing
    return 0;
}

