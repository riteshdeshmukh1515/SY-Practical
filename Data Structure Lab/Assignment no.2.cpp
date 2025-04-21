#include<iostream>
using namespace std;
   
   class CMS
   {
       string name;
       string phone;
       int donation;
       CMS *lc, *rc;
     
     public:
     
          void create();
          void insert(CMS *, CMS *);
          void display(CMS *root);
          void displayleaf(CMS *root);
          int ht(CMS* root);
          
          
   }*root, *st[100];
   
   void CMS :: create()
   {
    
     int ch;
     CMS *next;
     root = new CMS;
     cout<<"\nEnter the Name: ";
     cin>>root->name;
     cout<<"Enter the Phone number: ";
     cin>>root->phone;
     cout<<"Enter the Donation: ";
     cin>>root->donation;
     root->lc=root->rc=NULL;
     
     do
     {
       cout<<"\nYou want to add new donor enter (1/0): ";
       cin>>ch;
       
       if(ch==1)
       {
        next = new CMS;
        cout<<"\nEnter the Name: ";
        cin>>next->name;
        cout<<"Enter the Phone number: ";
        cin>>next->phone;
        cout<<"Enter the Donation: ";
        cin>>next->donation;
        next->lc=next->rc=NULL;
        insert(root, next);
       }
       
     }while(ch==1);
   }
   
   
   
   void CMS :: insert(CMS *root, CMS *next)
   {
     char ch1;
     
     cout<<"Where you want to insert "<<next->name<<" of "<<root->name<< " (L or R): ";
     cin>>ch1;
     
     if(ch1=='L' || ch1=='l')
     {
       if(root->lc == NULL)
       {
         root->lc = next;
       }
       else
       {
        insert(root->lc, next);
       }
     }
     
     if(ch1=='R' || ch1=='r')
     {
       if(root->rc == NULL)
       {
         root->rc = next;
       }
       else
       {
        insert(root->rc, next);
       }
     }
     
    
     
   }
   
   
   
   void CMS :: display(CMS *root)
   {
     CMS *temp;
     int top = -1;
     
     cout<<"\nDName\tMobNo\tDonation(Rs.)";
     temp = root;
     
     if(root != NULL)
     {
       
       do
       {
         while(temp != NULL)
         {
           top++;
           st[top]=temp;
           temp=temp->lc;
         }
         
         if(top != -1)
         {
         
           temp = st[top];
           top--;
           
            cout<<"\n"<<temp->name<<"\t"<<temp->phone<<"\t"<<temp->donation;
           temp = temp->rc;
         }
         
         
       }while(temp != NULL || top != -1);
           
      
     }
     
   }
   
   void CMS :: displayleaf(CMS *root)
   {
     CMS *temp;
     int top = -1;
     cout<<"\nThe Leaf Donors are: ";
     cout<<"\n\nDName\tMobNo\tDonation(Rs.)";
     temp = root;
     
     if(root != NULL)
     {
       
       do
       {
         while(temp != NULL)
         {
           top++;
           st[top]=temp;
           temp=temp->lc;
         }
         
         if(top != -1)
         {
           
           temp = st[top];
           top--;
           
           if(temp->lc == NULL && temp->rc == NULL)
           {
           
             cout<<"\n"<<temp->name<<"\t"<<temp->phone<<"\t"<<temp->donation;
           }
           
           temp = temp->rc;
         
        }
         
         
       }while(temp != NULL || top != -1);
           
      
     }
   }
   
   int CMS :: ht(CMS* root) 
   {
   int fht=0, lht=0, rht=0;
       if (root == NULL) 
       {
           return 0; 	// Base case: Empty tree has height 0
       }
       else
       {
        lht = ht(root->lc);  	// Height of left subtree
        rht = ht(root->rc);        // Height of right subtree
       }
            
      
       
       if(lht>rht)
       {
         fht=lht+1;
       }
       else
       {
         fht=rht+1;
       }
       
       return(fht);
   }
   
   
   
   int main()
   {
     int ch;
    
     while(true)
     {
        cout<<"\n\nMenu.\n1.Creat Donor & Insert Donor.\n2.Display.\n3.Display Leaf Donors.\n4.Calculate Height Of Charity Tree.\n5.Exit.";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        
        switch(ch)
        {
          case 1:
              root->create();
              break;
              
          case 2:
               root->display(root);
               break;
               
          case 3:
               root->displayleaf(root);
               break;
               
          case 4:
               if (root != NULL) {
                  cout << "\nThe height of the Charity tree is: " << root->ht(root) << "\n";
                   } else {
                       cout << "Tree is empty.\n";
                   }
                   break;
   
               break;
               
          case 5:
               return 0;
               
               default:
               cout<<"\nWrong choice.";
               
         }
         
      }
      
   }
