#include<iostream>
#include<string>
using namespace std;
class mls{
    public:
      int tn;
      string name,art;
      mls *next,*prev;
      void accept();
      void display();
      void display_reverse();
      void modify();
      void search();
      void remove();
}*start=NULL,*End=NULL;

void mls :: accept()
{
    mls *nnode,*temp;
    nnode=new mls;
    cout<<"enter the data of album:tn,name and artist::\n";
    cin>>nnode->tn>>nnode->name>>nnode->art;
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
        nnode->prev=temp;
        
        End=nnode;
    }

}
void mls:: display(){
    mls *temp=start;
    int cnt=0;
    if(temp==NULL)
    {
        cout<<"the list is empty";
    }
    else{
        while(temp!=NULL)
        {
            cout<<temp->tn<<"\t"<<temp->name<<"\t"<<temp->art;
            temp=temp->next;
            cout<<"\n";
            cnt++;

        }
    }
    cout<<"total no of records present:"<<cnt;

}
void mls:: display_reverse(){
    mls *temp=End;
   
        while(temp!=0)
        {
            cout<<temp->tn<<"\t"<<temp->name<<"\t"<<temp->art;
            temp=temp->prev;
            cout<<"\n";
        }
}

void mls::search(){
    mls *temp=start;
    string nn;
    cout<<"enter name to search\n";
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
                cout<<temp->tn<<"\t"<<temp->name<<"\t"<<temp->art;
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

void mls::modify(){
    mls *temp=start;
    string nn;
    cout<<"enter name to modify\n";
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
                cin>>temp->tn>>temp->name>>temp->art;
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

void mls::remove(){
    mls *p,*q;
    mls *temp=start;
    string nn;
    cout<<"enter name to delete\n";
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
    mls obj;
    int choice;

    while(true)
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Accept Data\n";
        cout << "2. Display Data\n";
        cout << "3. Display Data reverse\n";
        cout << "4. Search Data\n";
        cout << "5. Modify Data\n";
        cout << "6. Remove Data\n";
        cout << "7. Exit\n";
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
                obj.display_reverse();
                break;
            case 4:
                obj.search();
                break;
            case 5:
                obj.modify();
                break;
            case 6:
                obj.remove();
                break;
            case 7:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
