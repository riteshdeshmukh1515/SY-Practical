#include <iostream>
using namespace std;
int n;
class student {
private:
    int rno; 
    string name;
    string address;
public:
    void accept();
    void display();
    void lsearch();
    void bsearch();
} S[100];

void student::accept()
{
    cout<<"Enter the roll no, name and address:";
    cin>>rno>>name>>address;
}
 void student:: display()
 {
     cout<<"\n"<<rno<<"\t"<<name<<"\t"<<address;

 } 
void student::lsearch()
{

 int target,i;
    cout<< "Enter the roll no. to search: ";
    cin>>target;
    for(int i=0;i<n;i++) {
        if (S[i].rno == target) {
            cout << "Roll no."<< target << "attended training program";
            S[i].display();
            return;
        }
    }
     cout << "Roll no."<< target << " not attending training program"<<endl;
}
void student::bsearch() {
    int target;
    cout<< "Enter the roll no. to search: ";
    cin>> target;

    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (S[mid].rno == target) {
             cout << "Roll no."<< target << "attended training program";
            S[mid].display();
            return;
        } else if (S[mid].rno < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Roll no."<< target << "not attending training program";
}

int main() {
    int choice;
    cout << "Enter the number of students: ";
    cin >> n;

    while (true) {
        cout<< "\nMenu:\n";
        cout<< "1. Enter student details\n";
        cout<< "2. Display student details\n";
        cout<< "3. Linear search\n";
        cout<< "4. Binary search\n";
        cout<< "5. Exit\n";
        cout<< "Enter your choice: ";
        cin>> choice;

        switch (choice) {
            case 1:
                for(int i=0;i<n;i++)
                 {
                    cout << "Enter details for student: " << i + 1 << endl;
                    S[i].accept();
                }
                break;

            case 2:
            cout << "Student Details:" << endl;
            cout<<"\n"<<"rno\tname\taddress";
                for(int i=0;i<n;i++)
                {
                    S[i].display();
                }
                break;

            case 3:
                S[0].lsearch();
                break;

            case 4:
                S[0].bsearch();
                break;

            case 5:
                cout << "Exiting the program." <<endl;
                break;

            default:
                cout << "Invalid choice" <<endl;
                continue;
        }

        if (choice == 5) {
            break; 
        }
    }

    return 0;
}
