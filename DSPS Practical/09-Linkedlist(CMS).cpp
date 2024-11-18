#include<iostream>
#include<string>
using namespace std;
class cms{
    public:
      int amt;
      string name,add;
      cms *next;
      void accept();
      void display();
      void modify();
      void search();
      void remove();
}*start=NULL;

void cms :: accept()
{
    cms *nnode,*temp;
    nnode=new cms;
    cout<<"enter the data of the donor: name and address::\n";
    cin>>nnode->name>>nnode->add;
    nnode->next=NULL;
    if(start==NULL)
      {
        start=nnode;
      }
    else {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nnode;
    }

}
void cms:: display(){
    cms *temp=start;
    int cnt=0;
    if(temp==NULL)
    {
        cout<<"the list is empty";
    }
    else{
        while(temp!=NULL)
        {
            cout<<temp->name<<"\t"<<temp->add;
            temp=temp->next;
            cout<<"\n";
            cnt++;

        }
    }
    cout<<"total no of reccords present:"<<cnt;

}

void cms::search(){
    cms *temp=start;
    string nn;
    cout<<"entter name to search\n";
    cin>>nn;
    int f=0;
    if(temp==NULL)
    {
        cout<<"the list is empty";
    }
    else{
        while(temp!=NULL)
        {   if(temp->name==nn)
            {
                cout<<temp->name<<"\t"<<temp->add;
                f=1;
                break;
            }  
            temp=temp->next; 

        }
    }
    if(f==0){
        cout<<"record not found\n";
    }

}

void cms::modify(){
    cms *temp=start;
    string nn;
    cout<<"entter name to modify\n";
    cin>>nn;
    int f=0;
    if(temp==NULL)
    {
        cout<<"the list is empty";
    }
    else{
        while(temp!=NULL)
        {   if(temp->name==nn)
            {   cout<<"enter the details\n";
                cin>>temp->name>>temp->add;
                f=1;
                break;
            }  
            temp=temp->next; 

        }
    }
    if(f==0){
        cout<<"record not found\n";
    }
}

void cms::remove(){
    cms *p,*q;
    cms *temp=start;
    string nn;
    cout<<"entter name to delete\n";
    cin>>nn;
    int f=0;
    if(temp==NULL)
    {
        cout<<"the list is empty\n";
    }
    else{
        while(temp!=NULL)
        {   if(temp->name==nn)
            {   p=temp;
                f=1;
                break;
            }
            q=temp;  
            temp=temp->next; 

        }
        q->next=p->next;
        delete p;
    }
    if(f==0){
        cout<<"record not found\n";
    }

}

int main()
{
    cms obj;
    int choice;

    while(true)
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Accept Data\n";
        cout << "2. Display Data\n";
        cout << "3. Search Data\n";
        cout << "4. Modify Data\n";
        cout << "5. Remove Data\n";
        cout << "6. Exit\n";
        cout << "Enter your choice:\n ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                obj.accept();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                obj.search();
                break;
            case 4:
                obj.modify();
                break;
            case 5:
                obj.remove();
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
