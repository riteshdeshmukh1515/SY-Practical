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
     
      
}h[100],b;
int n,temp=0,chain[100];
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
         chain[i]=-1;

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
        int pos=hh;
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
               /*if(pos!=hh)
               {
               if(chain[pos]!=-1)
                {   int x=chain[pos];
                    chain[x]=hh;
                }
                else{
                    chain[pos]=hh;
                }
            }*/
            if (pos != hh) {
                int prev = pos;
                while (chain[prev] != -1) {
                    prev = chain[prev];
                }
                chain[prev] = hh;
            }
            
               break;
               
            }
            else{
                hh=(hh+1)%n;
                pb++;
             /* if(chain[pos]!=-1)
                {   int x=chain[pos];
                    chain[x]=hh;
                }
                else{
                    chain[pos]=hh;
                }*/
            }
        }
     }
}

void stud::display()
{   cout<<"loc\tprn\tname\taddress\tprobe\tchain";
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<c[i]<<"\t"<<key[i]<<"\t"<<h[i].name<<"\t"<<h[i].address<<"\t"<<probe[i]<<"\t"<<chain[i];
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
/*
void stud::search(int p, int kk) {
    int start = kk;  
    while (true) {
        if (h[kk].prn == p) {
            cout << "Record found at location " << c[kk] << "\n";
            return;
        }

        kk = (kk + 1) % n;  
        
        
        if (kk == start) {
            cout << "Record not found\n";
            return;
        }
    }
}
*/
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
    int tempProbe;
   
    while (key[deleted_index] != -1) {

        if (key[deleted_index] == prn_to_delete) {
            tempProbe=probe[deleted_index];

           if(chain[deleted_index]==-1) 
            {
            
            key[deleted_index] = -1;  
            h[deleted_index].prn = -1;  
            h[deleted_index].name = "null";  
            h[deleted_index].address = "null"; 
            probe[deleted_index] = 0;  

           
           
            cout << "Record with PRN " << prn_to_delete << " has been deleted.\n";
            return; 
            }
            else{
                int x = deleted_index;
                while (chain[x] != -1) {
                    int next = chain[x];
            
                    key[x] = key[next];
                    h[x].prn = h[next].prn;
                    h[x].name = h[next].name;
                    h[x].address = h[next].address;
                    probe[x] = tempProbe;
            
                    
                    if (chain[next] == -1) {
                        
                        key[next] = -1;
                        h[next].prn = -1;
                        h[next].name = "null";
                        h[next].address = "null";
                        probe[next] = 0;
                        chain[x] = -1; 
                        break;
                    }
            
                    x = next;
                }
            
                cout << "\nRecord deleted successfully\n";
                return;
                
            }
        }

       else{
        deleted_index = (deleted_index + 1) % n;
       }
    }
    
    cout << "Record not found.\n";  
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
