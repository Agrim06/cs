#include <iostream>
using namespace std;

class BANK_ACCOUNT {
private:
    int accountNumber;
    string accountHolderName;
    float balance , interest ,  finalBalance;

public:
    void read() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Account Holder Name: ";
        cin >> accountHolderName;

        cout << "Enter Balance: ";
        cin >> balance;
    }

    void calculate() {
        interest = 0.05 * balance;
        finalBalance = balance + interest;
    }

    void display() {
        cout << "\nAccount Number   : " << accountNumber;
        cout << "\nAccount Holder   : " << accountHolderName;
        cout << "\nBalance          : " << balance;
        cout << "\nInterest (5%)    : " << interest;
        cout << "\nFinal Balance    : " << finalBalance << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of account holders: ";
    cin >> n;

    BANK_ACCOUNT accounts[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Account Holder " << i + 1 << endl;
        accounts[i].read();
        accounts[i].calculate();
    }

    cout << "\n\n--- Account Details ---";
    for (int i = 0; i < n; i++) {
        accounts[i].display();
    }

    return 0;
}
