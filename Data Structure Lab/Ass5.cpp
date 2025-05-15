/*you are planning your wedding and need to select marraige halll location from a list of available option you want to find the shortest path from your current location to visit all the marraige hall locn and determine the optimal route that minimize travel  distance and time use appropriate ds and algo to implement it */

#include<iostream>
using namespace std;
int v;
class Marraige
{
private:
   
    int i=0,j=0;
    string city[10];
    int fuel;
    int a[100][100];
    
    
   
public:
    void create();
    void display();
    void ssp();
}f;

void Marraige::create()
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

void Marraige::ssp()
{     int dist[10];
    int visited[10];
     dist[0]=0;
     visited[0]=0;
     for(int i=1;i<v;i++)
     {
        dist[i]=999;
        visited[i]=0;
     }
     for(int i=0;i<v;i++)
     {
         for(int j=0;j<v;j++)
         {
            if(a[i][j]&&!visited[j]&&dist[i]+a[i][j]<dist[j])
            {
               dist[j]=dist[i]+a[i][j];
               cout<<dist[j];
             }
          }
         visited[i]=1;
      }
     for(int i=1;i<v;i++)
     {
        cout<<"distance from\t"<<city[0]<<"\tto\t"<<city[i]<<"::"<<dist[i]<<"\n";
     }
}
void Marraige::display() {
    cout << "\nDISTANCE Matrix:\n";
    
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
        cout<<"enter your choice\n1.enter the cities data and fuel required\n2.Find single source shortest path\n3.adj matrix\n4.Exit\n";
        cin>>n;
        switch(n)
        {
            case 1:
            f.create();
            break;
            case 2:
            f.ssp();
            break;
            case 3:
            f.display();
            break;
            case 4:
            return 0;
            break;
            default:
            cout<<"wrong choice";

        }

    }
    
    return 0;
}
