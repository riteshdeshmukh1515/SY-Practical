#include <iostream>
using namespace std;

class Bank {
public:
    int accno;
    double balance;
    char name[100];
    void accept();
    void deposit(int accno, int amount);
    void withdraw(int accno, int amount);
    void display(int accno); 
} a[100];

int n = 0; 

void Bank::accept() {
    cout << "Enter name of the depositor: ";
    cin >> name;
    cout << "Enter account number: ";
    cin >> accno;
    cout << "Enter initial balance: ";
    cin >> balance;
}

void Bank::deposit(int accno, int amount) {
    for (int i = 0; i < n; i++) {
        if (a[i].accno == accno) {
            if (amount > 0) {
                a[i].balance += amount;
                cout << "Deposit successful. New balance: \n" << a[i].balance ;
            } else {
                cout << "Invalid deposit amount.\n" ;
            }
            return;
        }
    }
    cout << "Account not found.\n" ;
}

void Bank::withdraw(int accno, int amount) {
    for (int i = 0; i < n; i++) {
        if (a[i].accno == accno) {
            if (amount > a[i].balance) {
                cout << "Insufficient funds. Withdrawal unsuccessful.\n" ;
            } else if (amount <= 0) {
                cout << "Invalid withdrawal amount.\n" ;
            } else {
                a[i].balance -= amount;
                cout << "Withdrawal successful. New balance:\n " << a[i].balance ;
            }
            return;
        }
    }
    cout << "Account not found.\n" ;
}

void Bank::display(int accno) {
    for (int i = 0; i < n; i++) {
        if (a[i].accno == accno) {
            cout << "\nName: " << a[i].name << "\tAccount Number: " << a[i].accno << "\tBalance: " << a[i].balance ;
            return;
        }
    }
    cout << "Account not found.\n" ;
}

int main() {
    int choice;

    cout << "Enter the number of user data you want to insert:\n ";
    cin >> n;
    if (n > 100) {
        cout << "Maximum limit is 100 accounts. Setting to 100.\n";
        n = 100;
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter details for account " << (i + 1) << ":" ;
        a[i].accept();
    }

    do {
        cout << "\nBank System Menu\n";
        cout << "1. Deposit amount\n";
        cout << "2. Withdraw amount\n";
        cout << "3. Display account details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int accno, amount;
                cout << "Enter account number: ";
                cin >> accno;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                a[0].deposit(accno, amount); 
                break;
            }
            case 2: {
                int accno, amount;
                cout << "Enter account number: ";
                cin >> accno;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                a[0].withdraw(accno, amount);
                break;
            }
            case 3: {
                int accno;
                cout << "Enter account number: ";
                cin >> accno;
                a[0].display(accno); 
                break;
            }
            case 4:
               return 0;
            default:
                cout << "Invalid choice\n" ;
        }
    } while (choice != 4);

    return 0;
}
