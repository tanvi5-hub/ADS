//============================================================================
// Name        : hashing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
# define max 10
using namespace std;
class dictionary
{
	string word;	//key
	string mean;	//value
public:
	dictionary()
{
		word=" ";
		mean=" ";
}
	friend class hashing;
};

class hashing
{
	dictionary arr[10];
	int p;
public:
	void create(int q)
	{
		p=0;
		int x;
		string key,value;
		char ans;
		do
		{
			cout<<"Enter the keyword"<<endl;
			cin>>key;
			cout<<"Enter the meaning"<<endl;
			cin>>value;
			if(q==1)
			{
				insert1(key,value);
			}
			if(q==2)
			{
				insert2(key,value);
			}
			cout<<"Do you want to enter more data"<<endl;
			cin>>ans;
			if(ans=='n')
				break;
			else
				continue;
			p++;
		}while(p<10);
		if(p==10)
		{
			cout<<"Cannot fill more information"<<endl;
			return;
		}
	}
	int hf(string key)
	{
		char ch=key.at(0);
		return int(ch);
	}
	//LINEAR PROBING WITHOUT REPLACEMENT
	void insert1(string key, string value)
	{

		int index=hf(key)%10;

		if(arr[index].word==" ")
		{
			arr[index].word=key;
			arr[index].mean=value;
		}
		else
		{
			int q=0;
			while(arr[index].word!=" ")
			{
				index=(index+1)%max;
				q++;
				if(q==10)
				{
					cout<<"No space to enter data"<<endl;
					return;
				}
			}
			arr[index].word=key;
			arr[index].mean=value;
		}
	}
	//LINEAR PROBING WITH REPLACEMENT
	void insert2(string key,string value)
	{
		int index=hf(key)%10;
		if(arr[index].word==" ")
		{
			arr[index].word=key;
			arr[index].mean=value;
		}
		else
		{
			int q=0;
			int p=hf(arr[index].word)%10;
			if(p==index)
			{
				while(arr[index].word!=" ")
				{
					index=(index+1)%10;
					q++;
					if(q>=10)
					{
						cout<<"No space to enter data"<<endl;
						return;
					}
				}
				arr[index].word=key;
				arr[index].mean=value;
			}
			else
			{
				dictionary s=arr[index];
				arr[index].word=key;
				arr[index].mean=value;
				while(arr[index].word!=" ")
				{
					index=(index+1)%10;
					q++;
					if(q==10)
					{
						cout<<"No space to enter data"<<endl;
						return;
					}
				}
				arr[index]=s;

			}
		}
	}
	int find(string x)
	{
		int index=hf(x)%10;
		if(arr[index].word==x)
		{
			return index;
		}
		else
		{
			int q=0;
			while(arr[index].word!=x)
			{
				index=(index+1)%max;
				q++;
				if(q==10)
				{
					break;
				}
			}
			if(arr[index].word!=x)
			{
				return -1;
			}
			return index;
		}
	}
	void delete_data()
	{
		string x;
		cout<<"Enter the keyword you want to delete"<<endl;
		cin>>x;
		int index=find(x);
		if(index==-1)
		{
			cout<<"Data to be deleted not present"<<endl;
			return;
		}
		arr[index].word=" ";
		arr[index].mean=" ";

	}
	void display()
	{
		for(int i=0;i<max;i++)
		{
			if(arr[i].word==" ")
			{
				cout<<"empty"<<endl;
			}
			else
			{

				cout<<arr[i].word<<" "<<arr[i].mean<<endl;
			}
		}
	}
	void found(int index)
	{
		cout<<"Data found"<<endl;
		cout<<arr[index].word<<" "<<arr[index].mean<<endl;
	}

};
int main()
{
	int ch,q=0;
	hashing obj;
	cout<<"-------MENU---------"<<endl;
	cout<<"1. Enter the information"<<endl;
	cout<<"2. Find the data"<<endl;
	cout<<"3. Delete the data"<<endl;
	do{
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
		{
			int z;
			cout<<"1. LINEAR PROBING WITHOUT REPLACEMENT"<<endl;
			cout<<"2. LINEAR PROBING WITH PREPLACEMENT"<<endl;
			cout<<"What do you want to perform?"<<endl;
			cin>>z;
			obj.create(z);
			cout<<"The information stored is as follows"<<endl;
			obj.display();
			break;
		}
		case 2:
		{
			string x;
			cout<<"Enter the keyword you want to find"<<endl;
			cin>>x;
			int n=obj.find(x);
			if(n==-1)
			{
				cout<<"Information not found"<<endl;
			}
			else
			{
					obj.found(n);

			}
			break;
		}
		case 3:
		{
			obj.delete_data();
			cout<<"The appended data is: ";
			obj.display();
			cout<<endl;
			break;
		}
		}
		cout<<"Do you want to continue(1 for yes/0 for no)?";
		cin>>q;
	}while(q==1);


	return 0;

}
