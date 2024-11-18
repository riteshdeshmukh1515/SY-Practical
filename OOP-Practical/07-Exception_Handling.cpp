#include<iostream>
using namespace std;

class Television
{
	int mdn,sz,pr;
public:
	friend istream& operator >> (istream&, Television&);
	friend ostream& operator << (ostream&, Television&);
};

istream& operator >> (istream& din,Television& t)
{
	int e;
	cout<<"\nEnter the Model no., television size in inches and prize :";
	din>>t.mdn>>t.sz>>t.pr;
	
	try
	{
		if(t.mdn > 9999 || t.sz < 12 || t.sz > 70 || t.pr > 5000 || t.pr < 0)
		{
			throw e;
		}
	}
	
	catch(int e)
	{
		cout<<"\nException is caught so all the values are being set to 0.";
		t.mdn = 0;
		t.sz = 0;
		t.pr = 0;
	}
	return din;
}

ostream& operator << (ostream& dout,Television& t)
{
	dout<<"\nThe details of the television are as follows:"<<endl;
	dout<<"Model no. = "<<t.mdn<<endl;
	dout<<"size = "<<t.sz<<endl;
	dout<<"Prize = "<<t.pr<<endl;
	return dout;
}

int main()
{
	Television t;
	
	int ch,choice;
	
	do
	{
		cout<<"\nMenu\n1.Insert the data of a television.\n2.Display the data of a television.\nEnter the choice:";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cin>>t;
				break;
				
			case 2:
				cout<<t;
				break;
			
			default:
				cout<<"\nInvalid choice.";
			
			
		}
		cout<<"Do you want to continue(1/0):";
		cin>>choice;
		
	}while(choice==1);
	return 0;
}
