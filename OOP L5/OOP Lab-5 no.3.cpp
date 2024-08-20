#include <iostream>
#include <string>
using namespace std;

// Base class
class Student {
protected:
    int roll_no;
    string name;
public:
    virtual void getdata() {
        cout << "Enter roll number: ";
        cin >> roll_no;
        cout << "Enter name: ";
        cin >> name;
    }
    virtual void displaydata() {
        cout << "Roll Number: " << roll_no << endl;
        cout << "Name: " << name << endl;
    }
};

// Derived class Test
class Test : virtual public Student {
protected:
    float marks1, marks2;
public:
    void getdata() override {
        Student::getdata();
        cout << "Enter marks for subject 1: ";
        cin >> marks1;
        cout << "Enter marks for subject 2: ";
        cin >> marks2;
    }
    void displaydata() override {
        Student::displaydata();
        cout << "Marks in Subject 1: " << marks1 << endl;
        cout << "Marks in Subject 2: " << marks2 << endl;
    }
};

// Derived class Sports
class Sports : virtual public Student {
protected:
    float score;
public:
    void getdata() override {
        Student::getdata();
        cout << "Enter sports score: ";
        cin >> score;
    }
    void displaydata() override {
        Student::displaydata();
        cout << "Sports Score: " << score << endl;
    }
};

// Derived class Result
class Result : public Test, public Sports {
private:
    float total;
public:
    void getdata() override {
        Test::getdata();
        Sports::getdata();
    }
    void displaydata() override {
        Test::displaydata();
        Sports::displaydata();
        total = marks1 + marks2 + score;
        cout << "Total Marks: " << total << endl;
    }
};

int main() {
    Result student;
    student.getdata();
    student.displaydata();
    return 0;
}

/*If Student is not made virtual,the Result class will inherit two copies 
of Student (one from Test and one from Sports). This leads to ambiguity when 
accessing members of Student, as the compiler cannot determine which instance to use*/

