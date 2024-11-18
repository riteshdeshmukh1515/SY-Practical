
#include<iostream>
using namespace std;
int n;

template<class T>

void selsort(T a[])
{
  cout<<"\nEnter the size of array: ";
  cin>>n;
  
  cout<<"Enter the array elements: ";
  for(int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  for(int i=0; i<n; i++)
  {
   for(int j=i+1; j<n; j++)
   {
    if(a[i]>a[j])
    {
     T temp = a[i];
     a[i] = a[j];
     a[j] = temp;
     
   }
  }
  }  
  cout<<"\nThe array elements is: ";
  for(int i=0; i<n; i++)
  {
   cout << a[i] << " " ;
  }

}

int main()
{
 int ch;
 
 int a[10]={0};
 double a1[10]={0.0};
 char a2[10]={'a'};
 
 while(true)
 {
 cout<<"\n\nMenu.\n1.Sort Integer array.\n2.Sort Float array.\n3.Sort Character array.\n4.Exit.";
 cout<<"\nEnter your choice: ";
 cin>>ch;
 
 switch(ch)
 {
 case 1: selsort(a);
 	 break;
 	 
 case 2: selsort(a1);
 	 break;
 	 
 case 3: selsort(a2);
 	 break;
 case 4: 
 	return 0;
 	 
 	 
 default: 
     cout<<"\nWrong Choice.";
     break;
     
     }
    }
    
}
