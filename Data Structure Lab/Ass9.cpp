#include<iostream>
using namespace std;
class heap{
    public:
    int A[100];
    int parent,loc;
    int n=0,value;
    void Insert(int value);
    void display();
    void swap(int a,int b);
    void delet();
        
}obj;

void heap :: Insert(int value)
{  
    n++;
    A[n]=value;
    loc=n;
    while(loc>1)
    {
        parent=loc/2;
        if(A[parent]<A[loc])
        {
            swap(parent,loc);
            loc=parent;

        }
        else{
            return;
        }
    }
}
void heap :: swap(int a,int b)
{
    int temp =A[a];
    A[a]=A[b];
    A[b]=temp;
        
}
void heap::delet() {

    if (n == 0) {
        cout << "Heap is empty.\n";
        return;
    }

    cout << "Deleted Root element: " << A[1] << endl;
    A[1] = A[n];  //  last element to root
    n--;          

    int i = 1;

    while (2 * i <= n) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int large = i;

        if (left <= n && A[left] > A[large]) {
            large = left;
        }
        if (right <= n && A[right] > A[large]) {
            large = right;
        }

        if (large != i) {
            swap(i, large);
            i = large;
        } else {
            break;
        }
    }
}


void heap :: display()
{   if (n == 0) {
    cout << "Heap is empty.\n";
    return;
}else{
    cout << "Elements in this max Heap: ";
    for (int i = 1; i <= n; i++) 
    {
        cout << A[i] << " ";
    }
    cout<<"\n";
    }
    
}
int main() {
    int choice, value;

    while (true) {
        cout << "\n";
        cout << "1. Insert\n";
        cout << "2. Delete \n";
        cout << "3. Display Heap\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                obj.Insert(value);
                break;

            case 2:
                obj.delet();
                break;

            case 3:
                
                obj.display();
                break;

            case 4:
                cout << "Exit\n";
                return 0;

            default:
                cout << "wrong hai bhai wapas daal\n";
        }
    }

    return 0;
}
