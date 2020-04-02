#include<iostream>
#include<fstream>
using namespace std;
class student
{
	int rno;
	string name;
	public :
	student()
	{
		rno = -1;
		name = " ";
	}
	void getdata()
	{
		cout << "Enter name : ";
		cin >> name;
		cout << "Enter roll no : ";
		cin >> rno;
	}
	void disp()
	{
		cout << "Name : " << name;
		cout << endl << "Roll no : " << rno;
	}
	int getr()
	{
		return rno;
	}
};
class fop
{
	student sp[10], sg;
	public :
	fop(){};
	void init()
	{
		ofstream fout;
		fout.open("dat.txt",ios::out|ios::binary);
		for(int i = 0;i<10;i++)
			fout.write((char*)&sg,sizeof(sg));
		fout.close();
	}
	void create(int i)
	{
		fstream fout;
		int rp,rg,r;
		fout.open("dat.txt",ios::in|ios::out|ios::binary);
			sp[i]=student();
			sg = student();
			sp[i].getdata();
			rp = sp[i].getr();
			rp = rp%10;
			fout.seekg((sizeof(sg))*rp,ios::beg);
			fout.read((char*)&sg,sizeof(sg));
			rg = sg.getr();
			if(rg == -1)
			{
				fout.seekp((sizeof(sp[i]))*rp,ios::beg);
				fout.write((char*)&sp[i],sizeof(sp[i]));
				return;
			}
			else
			{
				r = rp;
					fout.seekg((sizeof(sg))*rp,ios::beg);
					fout.read((char*)&sg,sizeof(sg));
					rg = sg.getr();
					display();
				while(rg != -1)
				{
					
					r = (r+1)%10;
					fout.seekg((sizeof(sg))*r,ios::beg);
					fout.read((char*)&sg,sizeof(sg));
					rg = sg.getr();
				}
				fout.seekp((sizeof(sp[i]))*r,ios::beg);
				fout.write((char*)&sp[i],sizeof(sp[i]));
			}
		
		fout.close();
	}
	void display()
	{
		
		cout << "in";
		fstream fout;
		fout.open("dat.txt",ios::in|ios::out|ios::binary);
		for(int i = 0;i<10;i++)
		{
			fout.seekg((sizeof(sg))*i,ios::beg);
			fout.read((char*)&sg,sizeof(sg));
			sg.disp();
			cout << endl;
		}
		fout.close();
	}
	void find()
	{
		int r,rg,r1;
		fstream fout;
		fout.open("dat.txt",ios::in|ios::out|ios::binary);
		cout << "Enter roll no : ";
		cin >> r;
		r1 = r%10;
		while(rg != r && rg != r1)
		{
			r1 = (r1+1)%10;
			fout.seekg((sizeof(sg))*r1,ios::beg);
			fout.read((char*)&sg,sizeof(sg));
			rg = sg.getr();
		}
		if (rg == r1)
		{
			cout << "not found";
		}
		else
		{
			fout.seekp((sizeof(sg))*r1,ios::beg);
			fout.read((char*)&sg,sizeof(sg));
			sg.disp();
		}
		fout.close();
	}
};
int main()
{
	fop f;
	f.init();
	for(int i = 0;i<10;i++)
	{
		f.create(i);
		f.display();
		cout << endl;
	}
	for(int i = 0;i<5;i++){
	f.find();
	}
}
