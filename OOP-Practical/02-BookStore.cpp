#include<iostream>
#include<cstring>
using namespace std;
int n;

class books{
    private:
    char *tt;
    char *auth;
    char *pub;
    int price;
    int   sp;

    public:
    void accept();
    void display();
    void buy(int n);
    books();
    ~books()
    {
        delete tt;
        delete auth;
        delete pub;
        cout<<"record cleared\n";
    }
   

}b[10];
books :: books(){
    tt=new char;
    auth=new char;
    pub=new char;
    strcpy(tt,"empty");
    strcpy(auth,"empty");
    strcpy(pub,"empty");
    price=0;
    sp=0;
}

void books::accept()
{
    cout<<"enter the title ,author, publisher, price and stock position of the books:- ";
    cin>>tt>>auth>>pub>>price>>sp;

}
void books::display()
{
    cout<<"\n"<<tt<<"\t"<<auth<<"\t"<<pub<<"\t"<<price<<"\t"<<sp;

}
void books :: buy(int n)
{   int f=0,cp,f1=0,total;
    char *title,*author;
    title=new char;
    author=new char;
    cout<<"enter title and author :";
    cin>>title>>author;
    for(int i=0;i<n;i++)
    {
        if(strcmp(title,b[i].tt)==0 && strcmp(author,b[i].auth)==0)
    
        {

           f=1;
           cout<<"enter number of copies :";
           cin>>cp;
           if(cp<=b[i].sp)
           {
            f1=1;
            total=b[i].price*cp;
            b[i].sp-=cp;
            cout<<"total cost is"<<total;

           }
           break;

        }

    }
    if(f==0)
    {
        cout<<"book not available";
    }
    if(f==1&&f1==0)
    {
        cout<<"book is available but not sufficient copies";

    }
}
int main()
{
    int choice;
    

    while (true) {  
        cout << "\nMenu:\n";
        cout << "1. Add Book data\n";
        cout << "2. Display Books\n";
        cout << "3. Buy Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            cout<<"enter the no of books you want to enter :";
            cin>>n;
                for (int i = 0; i < n; i++) {
                    b[i].accept();
                }
                break;

            case 2:
                for (int i = 0; i <10; i++) {
                    b[i].display();
                }
                break;

            case 3:
                b[0].buy(n);  
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
