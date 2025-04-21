#include<iostream>
using namespace std;
int v;
class Flight
{
private:
   
    int i=0,j=0;
    string city[10];
    int fuel;
    int a[100][100];
public:
    void accept();
    void display();
}f;

void Flight::accept()
{    
    cout<<"how many cities you want to insert";
    cin>>v;
   for(int i=0;i<v;i++)
   {
     cout<<"enter the city no\t"<<i+1<<":";
     cin>>city[i];
   }
   for(int i=0;i<v;i++)
   {
     for(int j=i;j<v;j++)
     {
        if(i==j)
        {
            a[i][j]=0;
        }
        else{
            cout<<"enter the fuel required for "<<city[i]<<"\tto\t"<<city[j]<<"\n";
            cin>>a[i][j];
            a[j][i]=a[i][j];
        }
     }
   }
}
/*void Flight::display()
{
    for(int i=0;i<v;i++)
    {
      for(int j=0;j<v;j++)
      {   cout<<city[i][j]<<"\t";
          cout<<a[i][j]<<"\t";
         }
      }
    
}*/
void Flight::display() {
    cout << "\nFuel Requirement Matrix:\n";
    
    cout << "\t";
    for (int i = 0; i < v; i++) {
        cout << city[i] << "\t";
    }
    cout <<"\n";
   
    
   
    for (int i = 0; i < v; i++) {
        cout << city[i] << "\t";  
        for (int j = 0; j < v; j++) {
            cout << a[i][j] << "\t";
        }
        cout <<"\n";
    }
}

int main()
{   int n;
    while(1)
    {
        cout<<"enter your choice\n1.enter the cities data and fuel required\n2.display the data\n";
        cin>>n;
        switch(n)
        {
            case 1:
            f.accept();
            break;
            case 2:
            f.display();
            break;
            case 3:
            return 0;
            break;
            default:
            cout<<"wrong choice";

        }

    }
    return 0;
}
