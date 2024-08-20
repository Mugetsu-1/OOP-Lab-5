#include <iostream>
using namespace std;

// Abstract base class
class CentralBank {
protected:
    float ird; // Interest rate for deposits
    float irl; // Interest rate for loans
public:
    virtual void getdata() = 0; // Pure virtual function
    virtual void displaydata() = 0; // Pure virtual function
    virtual float calculateInterestAmount(float amount, bool isDeposit) = 0; // Pure virtual function
    virtual ~CentralBank() {} // Virtual destructor
};

// Derived class NMB
class NMB : public CentralBank {
public:
    void getdata() override {
        cout << "Enter interest rate for deposits (NMB): ";
        cin >> ird;
        cout << "Enter interest rate for loans (NMB): ";
        cin >> irl;
    }

    void displaydata() override {
        cout << "NMB Bank - Interest Rate for Deposits: " << ird << "%" << endl;
        cout << "NMB Bank - Interest Rate for Loans: " << irl << "%" << endl;
    }

    float calculateInterestAmount(float amount, bool isDeposit) override {
        if (isDeposit) {
            return amount * (ird / 100);
        } else {
            return amount * (irl / 100);
        }
    }
};

// Derived class GlobalBank
class GlobalBank : public CentralBank {
public:
    void getdata() override {
        cout << "Enter interest rate for deposits (GlobalBank): ";
        cin >> ird;
        cout << "Enter interest rate for loans (GlobalBank): ";
        cin >> irl;
    }

    void displaydata() override {
        cout << "GlobalBank - Interest Rate for Deposits: " << ird << "%" << endl;
        cout << "GlobalBank - Interest Rate for Loans: " << irl << "%" << endl;
    }

    float calculateInterestAmount(float amount, bool isDeposit) override {
        if (isDeposit) {
            return amount * (ird / 100);
        } else {
            return amount * (irl / 100);
        }
    }
};

int main() {
    CentralBank* bank;

    // Using NMB
    bank = new NMB();
    bank->getdata();
    bank->displaydata();
    cout << "Interest on deposit of 1000: " << bank->calculateInterestAmount(1000, true) << endl;
    cout << "Interest on loan of 1000: " << bank->calculateInterestAmount(1000, false) << endl;
    delete bank;

    // Using GlobalBank
    bank = new GlobalBank();
    bank->getdata();
    bank->displaydata();
    cout << "Interest on deposit of 1000: " << bank->calculateInterestAmount(1000, true) << endl;
    cout << "Interest on loan of 1000: " << bank->calculateInterestAmount(1000, false) << endl;
    delete bank;

    return 0;
}

