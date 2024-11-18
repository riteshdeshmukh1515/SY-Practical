/* 	Pizza parlor accepting maximum M orders. 
	Orders are served in first come first served basis. 
	Order once placed cannot be cancelled. 
	Write C++ program to simulate the system using circular queue using array.  */



#include <iostream>
#include <string>
using namespace std;

class Pizza 
{
    int q[5];             
    string name[5];       
    string add[5];        
    int f, r;   
    bool firstOrder;          // Front and rear indices

public:
    Pizza() 
    {
        f = -1;
        r = -1;
        firstOrder = true;
    }

    void accept();
    void serve();
    void display();
};

void Pizza::accept() 
{
    if ((f == 0 && r == 4) || (r + 1) % 5 == f) 
    {
        cout << "\nKitchen is busy.\nYou cannot give the order.";
        return;
    }

    r = (r + 1) % 5; 			// Move to the next position circularly

    cout << "\nEnter Name: ";
    cin >> name[r];
    
    cout << "Enter Address: ";
    cin >> add[r];
    
    cout << "Enter Quantity: ";
    cin >> q[r];

    if (f == -1) 
    { 
        f = 0; 				// First order
    }

    // Calculate the bill
    
    int bill = q[r] * 100; 		// Base bill
    
    if (firstOrder) 
    {
        bill -= bill * 0.1; 		// Apply 10% discount
        cout<<"\nCongratulations..!\nYour order is first. So you get 10% discount.\n";
        firstOrder = false; 		// Set firstOrder to false after the first order
    }

    cout << "Your bill is: Rs. " << bill << endl; 
}

void Pizza::serve() 
{
    if (f == -1) 
    {
        cout << "\nKitchen is empty";
        return;
    }

    cout << "\nOrder delivered to: " << name[f] << endl;

    if (f == r) 
    { 
        f = r = -1; 			// Queue becomes empty after this dequeue
    } 
    else 
    {
        f = (f + 1) % 5; 		// Move to the next position circularly
    }
}

void Pizza::display() 
{
    if (f == -1) 
    {
        cout << "\nKitchen is empty";
        return;
    }

    cout << "\nOrders are: ";
    cout << "\nName\tAddress\tQuantity";
    int i = f;
    
    while (true) 
    {
        
        cout <<"\n"<< name[i] <<"\t"<< add[i] <<"\t"<< q[i];
        
        
        if (i == r) 
        break;
            
       i = (i + 1) % 5; 	// Move circularly
    }
   
    cout << endl;
}

int main() 
{
    Pizza Q; 
    int ch, n;

    while (true) 
    {
        cout<<"\n\n        PIZZA PRICE : 100 Rs ONLY";
        cout << "\nMenu.\n1.Accept Order\n2.Delivery Order\n3.Display\n4.Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) 
        {
            case 1:
                cout << "How many orders you want to accept: ";
                cin >> n;
                
                for (int i = 0; i < n; i++) 
                {
                    Q.accept();
                }
                break;
                
            case 2:
                Q.serve();
                break;
                
            case 3:
            	
                   Q.display();
                
                break;
                
            case 4:
                return 0;
                
            default:
                cout << "\nInvalid choice.";
                break;
        }
    }

    return 0;
}
