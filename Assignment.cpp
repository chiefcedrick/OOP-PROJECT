#include <iostream>
#include <string>

using namespace std;

class Account {
public:
    string name;
    string address;
    int accountNumber;
    double balance;

    Account(string name, string address, double initialDeposit) {
        this->name = name;
        this->address = address;
        this->balance = initialDeposit;
        this->accountNumber = 1000; // Starting account number, consider a more robust generation
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    string name, address;
    double initialDeposit;

    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Initial Deposit: ";
    cin >> initialDeposit;

    Account account(name, address, initialDeposit);

    while (true) {
        // Simplified menu for clarity
        cout << "\nMenu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                account.deposit(amount);
                cout << "Deposit successful!" << endl;
                break;
            }
            case 2: {
                double amount;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                if (account.withdraw(amount)) {
                    cout << "Withdrawal successful!" << endl;
                } else {
                    cout << "Insufficient balance!" << endl;
                }
                break;
            }
            case 3: {
                cout << "Balance: " << account.getBalance() << endl;
                break;
            }
            case 4: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice!" << endl;
            }
        }
    }

    return 0;
}
