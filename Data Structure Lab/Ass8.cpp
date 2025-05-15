#include<iostream>
#include<climits>
using namespace std;

class OBST{
    public:
    float c[100][100];
    float w[100][100];
    float r[100][100];
    int key[100];
    float p[100],q[100];
    void accept();
    void calculateOBST();
    void display();
    void print(int i,int j);

}obj;
int n;
void OBST::accept()
{
     cout<<"how many keys you want to insert";
     cin>>n;
     cout<<"Enter the keys";
     for(int i=0;i<n;i++)
     {
        cin>>key[i];
     }
     cout<<"Enter the successfull search probabilities";
     for(int i=1;i<=n;i++)
     {
        cin>>p[i];
     }
     cout<<"Enter the UNsuccessfull search probabilities";
     for(int i=0;i<=n;i++)
     {
        cin>>q[i];
     }
     
} 
void OBST::calculateOBST()
{   //float temp[10];
   for (int i = 0; i <= n; i++) {
    
      c[i][i] = 0;
      w[i][i] = q[i];
      r[i][i] = 0;
      }
    
  
  for (int i = 0; i <= n; i++)
   {
    for(int j=i+1;j<=n;j++ )
    {
    
    w[i][j]=p[j]+q[j]+w[i][j-1];
    
    }
  }
  
    
    for(int l=1;l<=n;l++)
    {
      
      for(int i=0;i<=n-l;i++)
      
    {      
        int j=i+l;
            //float minimum=999;
             //int minimum_K=-1;
      c[i][j]=INT_MAX;
                //w[i][j]=p[j]+q[j]+w[i][j-1];
                //int s=0;
               for(int k=i+1;k<=j;k++)
                {
                    //float cost=c[i][k-1]+c[k][j]+w[i][j];
                    //s++;
                    float cost=c[i][k-1]+c[k][j]+w[i][j];
                    if(cost<c[i][j])
                    {
                        c[i][j]=cost;
                        r[i][j]=k;
            
                }
               // c[i][j]=minimum;
               // r[i][j]=minimum_K;

            }
        }
}
}

void OBST::display()
{  //int i=0,j=n-1;
  //float root=r[i][j];
  
   cout << "\nCost Matrix (c):\n";
   for(int i = 0; i <= n; i++) {
       for(int j = i+1; j <= n; j++) {
           cout << c[i][j] << "\t";
       }
       cout << endl;
   }

   cout << "\nWeight Matrix (w):\n";
   for(int i = 0; i <= n; i++) {
       for(int j = i+1; j <= n; j++) {
           cout << w[i][j] << "\t";
       }
       cout << endl;
   }

   cout << "\nRoot Matrix (r):\n";
   for(int i = 0; i <=n; i++) {
       for(int j = i+1; j <= n; j++) {
           cout << r[i][j] << "\t";
       }
       cout << endl;
   }
   obj.print(0,n);



}
void OBST:: print(int i ,int j)
{
    int root=r[i][j];
    if(root==0)
    {
        return;
    }
    cout<<"key is:"<<key[root-1];

}
int main()
{
   obj.accept();
   obj.calculateOBST();
   obj.display();
   return 0;
}