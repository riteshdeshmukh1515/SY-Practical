#include<iostream>
#include<cstring>
using namespace std;

int i, n;
class PIS {
    public:static int cnt;

    
    int pn, cn, wt, ht, dob;
    char *name, *add, *dln, bg[3];

public:
    // Default constructor
    PIS() {
        name = new char[50];  // Allocate memory for strings
        add = new char[100];
        dln = new char[20];
        strcpy(name, "vvvv");
        strcpy(add, "WWW");
        strcpy(dln, "dl100");
        pn = 100;
        cn = 99999;
        wt = 10;
        ht = 10;
        dob = 2024;
        strcpy(bg, "O+");
    }

    // Parameterized constructor
    PIS(int h, int w, int d) {
        name = new char[50];
        add = new char[100];
        dln = new char[20];
        ht = h;
        wt = w;
        dob = d;
    }

    // Copy constructor
    PIS(const PIS &ss) {
        name = new char[50];
        add = new char[100];
        dln = new char[20];
        strcpy(name, ss.name);
        strcpy(add, ss.add);
        strcpy(dln, ss.dln);
        pn = ss.pn;
        cn = ss.cn;
        wt = ss.wt;
        ht = ss.ht;
        dob = ss.dob;
        strcpy(bg, ss.bg);
    }

    // Destructor
    ~PIS() {
        delete name;  
        delete add;
        delete dln;
        cout << "\n Data cleared";
    }

    
    static void displaycnt() {
        cout << "\nTotal number of Records in the database: " << cnt;
    }

   
    void accept() {
        
        cout << "\nEnter the PIS (Name, Address, DLN, Policy No., Contact No., Height, Weight, DOB, Blood Group):\n";
        cin >> name >> add >> dln >> pn >> cn >> ht >> wt >> dob >> bg;
    }

    
    inline void display() {
        cout << "\n" << name << "\t" << add << "\t" << dln << "\t" << pn << "\t" << cn;
    }

    
    friend void search(PIS[], int);

   
    void update();

   
    void Delete();
}p[100];


int PIS::cnt = 0;




void PIS::update() {
    int po, f = 0;
    cout << "\nEnter the policy number: ";
    cin >> po;
    for (i = 0; i < n; i++) {
        if (po == p[i].pn) {
            f = 1;
            p[i].accept();
            break;
        }
    }
    if (f == 0)
        cout << "\nRecord not found";
}


void PIS::Delete() {
    int q, f = 0;
    cout << "\nEnter the policy number: ";
    cin >> q;
    for (i = 0; i < n; i++) {
        if (q == p[i].pn) {
            f = 1;
            for (int j = i; j < n - 1; j++) {
                p[j] = p[j + 1];
            }
            n--;
            cnt--;
            break;
        }
    }
    if (f == 0)
        cout << "\nRecord not found";
}


void search(PIS p[], int) {
    int f = 0, pp;
    cout << "\nEnter the Policy number for search: ";
    cin >> pp;
    for (i = 0; i < n; i++) {
        if (pp == p[i].pn) {
            f = 1;
            p[i].display();
            break;
        }
    }
    if (f == 0)
        cout << "\nDetails not found";
}


int main() {
    int ch;

    

    do {
        cout << "\nMain Menu";
        cout << "\n1. Accept\n2. Display\n3. Search\n4. Display number of records\n5. Update\n6. Delete\n7.exit(press 0)";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
             cout << "\nEnter the number of records: ";
             cin >> n;
             
            for (i = 0; i < n; i++) {
                p[i].accept();
               PIS :: cnt++;
            }
            break;
        case 2:
            cout << "\nName\tAddress\tDLN\tPolicy No.\tContact No.";
            for (i = 0; i < n; i++) {
                p[i].display();
            }
            break;
        case 3:
            search(p, i);
            break;
        case 4:
            PIS::displaycnt();
            break;
        case 5:
            p[i].update();
            break;
        case 6:
            p[i].Delete();
            break;
        default:
            cout << "\nInvalid choice!";
            break;
        }
    } while (ch != 0);

    return 0;
}
