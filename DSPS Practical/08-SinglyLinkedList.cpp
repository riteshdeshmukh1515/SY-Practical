/* Implement Library Management System (LSM) Using Singly Linked List  */
#include <iostream>
using namespace std;

struct Node 
{
    string tt, pb;
    int pz, bid;
    Node* next;
};

class LinkedList 
{

private:
    Node* head;
    
public:
    LinkedList() 
    {
        head = NULL;
    }
    
    void insertAtFirst() 
    {
        Node* newNode = new Node;
        cout << "Enter the title & publisher: ";
        cin >> newNode->tt >> newNode->pb;
        cout << "Enter the price & book id: ";
        cin >> newNode->pz >> newNode->bid;
        
        newNode->next = head;
        head = newNode;
    }

    void insertAtLast() 
    {
        Node* newNode = new Node;
        cout << "Enter the title & publisher: ";
        cin >> newNode->tt >> newNode->pb;
        cout << "Enter the price & book id: ";
        cin >> newNode->pz >> newNode->bid;
        newNode->next = NULL;
        
        if (head == NULL) 
        {
            head = newNode;
        }
        else 
        {
            Node* temp = head;
            while (temp->next != NULL) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAfter() 
    {
        int bd;
        cout << "Enter the book id after which you want to insert the data: ";
        cin >> bd;
        
        Node* temp = head;
        
        while (temp->bid!=bd ) 
        {
           
            temp = temp->next;
            
        }
        
        if (temp == NULL) 
        {
            cout << "Invalid position!" << endl;
        } 
        else 
        {
            Node* newNode = new Node;
            cout << "Enter the title & publisher: ";
            cin >> newNode->tt >> newNode->pb;
            cout << "Enter the price & book id: ";
            cin >> newNode->pz >> newNode->bid;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteFirst() 
    {
        if (head == NULL) 
        {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast() 
    {
        if (head == NULL) 
        {
            cout << "List is empty." << endl;
            return;
        }
        
        if (head->next == NULL) 
        {
            delete head;
            head = NULL;
        } 
        else 
        {
            Node* temp = head;
            while (temp->next && temp->next->next) 
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }

    void deleteAtPosition() 
    {
        int bd;
        cout << "Enter the book id which you want to delete: ";
        cin >> bd;

        if (head == NULL) 
        {
            cout << "List is empty." << endl;
            return;
        }

        
        if (head->bid == bd) 		// Special case: Deleting the head node
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        
        Node* temp = head;		// General case: Deleting a non-head node
        while (temp->next != NULL && temp->next->bid != bd) 		
        {
            temp = temp->next;
        }

        if (temp->next == NULL) 
        {
            cout << "Book with ID " << bd << " not found!" << endl;
        } 
        else 
        {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }


    void display() 
    {
        if (head == NULL) 
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout<<"\n\nTitle\tPub\tprice\tbid";
        while (temp != NULL) 
        {
            
            cout << "\n"<< temp->tt << "\t"<< temp->pb << "\t" << temp->pz << "\t" << temp->bid;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() 
{
    LinkedList list;
    int  ch;

    while(true) 
    {
        cout << "\nMenu: \n1. Accept at first\n2. Accept at last\n3. Accept after book id\n4. Delete first\n5. Delete last\n6. Delete at book id\n7. Display\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) 
        {
            case 1:
                list.insertAtFirst();
                break;
            
            case 2:
                list.insertAtLast();
                break;
            
            case 3:
                list.insertAfter();
                break;
            
            case 4:
                list.deleteFirst();
                break;
            
            case 5:
                list.deleteLast();
                break;
            
            case 6:
                list.deleteAtPosition();
                break;
            
            case 7:
                list.display();
                break;
            
            case 8:
            	    return 0;
            	    
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        
    } 

    return 0;
}
