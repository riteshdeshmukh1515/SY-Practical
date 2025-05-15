/*job seeker preparing for intervciew in different location  you have a list of city where
interview are scheduled and you want to find the shortest path to visit the all locations
starting form your currtent location the robjective is to minimize the total travel distance
and time while ensuring you reach each locstion in time use appropriate ds and algorithm to
implement it*/

#include<iostream>
using namespace std;
int v;
class SP
{
private:
   
    int i=0,j=0;
    string city[10];
    int fuel;
    int a[100][100];
public:
    void create();
    void display();
    void sp();
}f;

void SP::create()
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
void SP::sp()
{
    int key[10],u;
    int parent[10];
    bool visited[10];
    for(int i=0;i<v;i++)
    {
        key[i]=999;
        parent[i]=999;
    }
    int min=999;
    key[0]=0;
    parent[0]=-1;
    for(int e=0;e<v-1;e++)
    {
        min=999;
        for(int j=0;j<v;j++)
        {
            if(!visited[j]&&min>key[i])
            {
                min=key[i];
                u=i;
            }
        }
        visited[u]=true;
        for(int j=0;j<v;j++)
        {
            if(!visited[j]&&a[u][j]&&a[u][j]<key[j])
            {
                parent[j]=u;
                key[j]=a[u][j];
            }
        }
    }

}

/*void SP::display() {
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
*/
int main()
{   int n;
    while(1)
    {
        cout<<"enter your choice\n1.enter the cities data and fuel required\n2.display the data\n";
        cin>>n;
        switch(n)
        {
            case 1:
            f.create();
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
