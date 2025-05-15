#include<iostream>
using namespace std;
class stud{
      public:
      int prn,k[10],hh;
      int key[100];
      int c[100],probe[100];
      string name,address;
      void create();
      void accept();
      void display();
      void search(int p,int kk);
      void modify(int p,int kk);
      void remove(int prn_to_delete);
      void reconstruct_after_deletion(int deleted_index);
      
}h[100],b;
int n,temp=0;
void stud::create()
{
    cout<<"enter the size of hash table you want to create";
    cin>>n;
    for(int i=0;i<n;i++)
    {
         c[i]=i;
         key[i]=-1;
         probe[i]=0;
         h[i].name="null";
         h[i].address="null";

    }
}
void stud::accept()
{   int ch;
    cout<<"enter how many record you want to insert";
    cin>>ch;
     cout<<"enter the keys";
     for(int i=0;i<ch;i++)
     {
         cin>>k[i];
     }
     for(int i=0;i<ch;i++)
     {  int pb=0;
        hh=k[i]%n;
        while(hh<=99)
        {
            if(key[hh]==-1)
            {  key[hh]=k[i];
               h[hh].prn=k[i];
               cout<<"enter the details of the student\n";
               cout<<"enter the name of the student with PRN::"<<h[hh].prn<<"\n";
               cin>>h[hh].name;
               cout<<"enter the addresss of the student wit PRN::"<<h[hh].prn<<"\n";
               cin>>h[hh].address;
               pb++;
               probe[hh]=pb;
               break;
               
            }
            else{
                hh++;
                pb++;
                if(hh>=n)
                {
                    hh=0;
                }
            }
        }
     }
}

void stud::display()
{   cout<<"loc\tprn\tname\taddress\tprobe";
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<c[i]<<"\t"<<key[i]<<"\t"<<h[i].name<<"\t"<<h[i].address<<"\t"<<probe[i];
    }
}
void stud::search(int p,int kk)
{
    
    if(h[kk].prn==p)
    {
        cout<<"record found at location"<<c[kk];
    }
    else{
        kk = (kk + 1) % n;
        temp+=1;
        
        if(temp==n)
        {
            cout<<"record not found\n";
            return;
        }
        else{
            b.search(p,kk);
        }
                                                        
    }

}

void stud::modify(int p,int kk)
{
    int start = kk;  
    while (true) {
        if (h[kk].prn == p) {
            cout << "Record found at location " << c[kk] << "\n";
            cout<<"Enter new details for PRN:"<<p;
            cout<<"Enter the name::";
            cin>>h[kk].name;
            cout<<"Enter the Address::";
            cin>>h[kk].address;

            return;
        }

        kk = (kk + 1) % n;  
        
        
        if (kk == start) {
            cout << "Record not found\n";
            return;
        }
    }
}

void stud::remove(int prn_to_delete) {
    
    int deleted_index = prn_to_delete % n;

   
    while (key[deleted_index] != -1) {
        if (key[deleted_index] == prn_to_delete) {
            
            key[deleted_index] = -1;  
            h[deleted_index].prn = -1;  
            h[deleted_index].name = "null";  
            h[deleted_index].address = "null"; 
            probe[deleted_index] = 0;  

           
            reconstruct_after_deletion(deleted_index);
            cout << "Record with PRN " << prn_to_delete << " has been deleted.\n";
            return; 
        }

       
        deleted_index = (deleted_index + 1) % n;
    }

    cout << "Record not found.\n";  
}
void stud::reconstruct_after_deletion(int deleted_index) {
    int next = (deleted_index + 1) % n; 
    while (key[next] != -1) {
        int temp_key = key[next];
        string temp_name = h[next].name;
        string temp_address = h[next].address;

        
        key[next] = -1;
        h[next].prn = -1;
        h[next].name = "null";
        h[next].address = "null";
        probe[next] = 0;

        
        int new_index = temp_key % n;
        int pb = 1;
        while (key[new_index] != -1) {
            new_index = (new_index + 1) % n;
            pb++;
        }

        key[new_index] = temp_key;
        h[new_index].prn = temp_key;
        h[new_index].name = temp_name;
        h[new_index].address = temp_address;
        probe[new_index] = pb;

       
        next = (next + 1) % n;
    }
}


int main()
{   int choice;
    while(1)
   {  cout<<"\nEnter your choice\n1.create table\n2.accept the details\n3.display the details\n4.search record\n5.modify record\n6.Remove record\n7.Exit program";
    cin>>choice;
    switch(choice)
    {
    case 1:
    b.create();
    break;
    case 2:
    b.accept();
    break;
    case 3:
    b.display();
    break;
    case 4:
    int p,kk;
    cout<<"Enter the prn yopu wnat to search\n";
    cin>>p;
    kk=p%n;
    temp = 0;
    b.search(p,kk);
    break;
    case 5:
    cout<<"Enter the prn you Want to update data\n";
    cin>>p;
    kk=p%n;
    b.modify(p,kk);
    break;
    case 6:
    int prn_to_delete;
    cout<<"enter the prn to delete::\n";
    cin>>prn_to_delete;
    b.remove(prn_to_delete);
    break;
    case 7:
    return 0;
    break;
    default:
    cout<<"wrong choice hai bhai";
 
    }
  }
}
