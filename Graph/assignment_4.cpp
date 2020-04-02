#include<iostream>
#include<string.h>
using namespace std;

class node
{
	private:
		string data;
		int weight;
		node *next;
	public:
		node(string a, int x)
		{
			data = a;
			weight = x;
			next = NULL;
		}
		friend class graph;
};

class graph
{
	private:
		int n;
		string city[20];
		node *head[20];
	public:	
		graph()
		{
			cout << "Enter the no. of cities to be represented on your network :" << endl;
			cin >> n;
			for(int i = 0; i < n; i++)
			{
				city[i] = " ";
				head[i] = NULL;
			}
 		}
 		void create_list();
 		void show_list();
 		void add_city();
 		void del_city();
 		void outdegree();
 		void indegree();
};

void graph::create_list()
{
	int x, cost;
	cout << "Enter city names :" << endl;
	cin.ignore(1);
	for(int i = 0; i < n; i++)
	{
		getline(cin, city[i]);
	}
	cout << "Cities entered are :" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << city[i] << " ";
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i != j)
			{
				cout << "Is there a direct flight between " << city[i] << " and " << city[j] << "?(1 for yes, 0 for no)" << endl;
				cin >> x;
				if(x == 1)
				{
					cout << "Enter the duration of flight :" << endl;
					cin >> cost;
					if(head[i] == NULL)
					{
						head[i] = new node(city[j], cost);
					}
					else
					{
						node *temp;
						temp = head[i];
						while(temp->next != NULL)
						{
							temp = temp->next;
						}
						temp->next = new node(city[j], cost);
					}
				}
			}
		}
	}
}

void graph::show_list()
{
	for(int i = 0; i < n; i++)
	{
		cout << city[i] << " -> ";
		if(head[i] != NULL)
		{
			node *temp;
			temp = head[i];
			while(temp != NULL)
			{
				cout << temp->data << ", " << temp->weight << " ; ";
				temp = temp->next;
			}
		}
		cout << endl;
	}
}

void graph::add_city()
{
	int x, cost;
	string city1;
	cout << "Enter city you wish to add to network :" << endl;
	cin >> city1;
	city[n] = city1;
	n = n + 1;
	head[n - 1] = NULL;
	cout << "The cities in network are :" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << city[i] << " ";
	}
	for(int i = 0; i < n - 1; i++)
	{
		cout << "Is there a direct flight between " << city[i] << " and " << city1 << "?(1 for yes, 0 for no)" << endl;
		cin >> x;
		if(x == 1)
		{
			cout << "Enter duration of flight :" << endl;
			cin >> cost;
			if(head[i] == NULL)
			{
				head[i] = new node(city1, cost);
			}
			else
			{
				node *temp;
				temp = head[i];
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = new node(city1, cost);
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << "Is there a direct flight between " << city1 << " and " << city[i] << "(1 for yes, 0 for no)" << endl;
		cin >> x;
		if(x == 1)
		{
			cout << "Enter the duration of flight :" << endl;
			cin >> cost;
			if(head[n - 1] == NULL)
			{
				head[n - 1] = new node(city[i], cost);
			}
			else
			{
				node *temp;
				temp = head[n - 1];
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = new node(city[i], cost);
			}
		}
	}
}

void graph::del_city()
{
	string city1;
	int cnt = 0;
	cout << "Enter city you wish to delete from network :" << endl;
	cin >> city1;
	int i = 0, k = 0;
	while(i < n)
	{
		if(city1 == city[i])
		{
			k = i;
			cnt++;
			break;
		}
		i++;
	}
	cout << endl;
	cout << "Position of city is :" << k << endl;
	if(cnt == 0)
	{
		cout << "City not present!" << endl;
		return;
	}
	if(k == n - 1)
	{
		cout << "Last City" << endl;
		head[n - 1] = NULL;
		n = n - 1;
	}
	else if(k != n - 1)
	{
		cout << "Not Last CIty!" << endl;
		for(int i = k; i < n; i++)
		{
			city[i] = city[i + 1];
		}
		city[n - 1] = " ";
		n = n - 1;
	}
	cout << "Cities in network now are :" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << city[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < n; i++)
	{
		node *p, *temp;
		p = head[i];
		temp = head[i]->next;
		while(temp != NULL)
		{
			if(p->data == city1)
			{
				head[i] = temp;
				delete p;
			}
			if(temp->data == city1)
			{
				p->next = temp->next;
				delete temp;
			}
			p = p->next;
			temp = temp->next;
		}
	}
}

void graph::outdegree()
{
	node *p;
	int cnt, sum;
	for(int i = 0; i < n; i++)
	{
		cnt = 0;
		sum = 0;
		p = head[i];
		cout << "No. of flights taking off from " << city[i] << " are :" << endl;
		while(p != NULL)
		{
			sum = sum + p->weight;
			p = p->next;
			cnt++;
		}
		cout << cnt << endl;
		cout << "Outdegree of " << city[i] << " = " << sum << endl;
	}
}

void graph::indegree()
{
	node *temp;
	string p;
	for(int i = 0; i < n; i++)
	{
		p = city[i];
		int cnt = 0;
		int sum = 0;
		for(int j = 0; j < n; j++)
		{
			temp = head[j];
			while(temp != NULL)
			{
				if(temp->data == p)
				{
					sum = sum + temp->weight;
					cnt++;
				}
				temp = temp->next;
			}
		}
		cout << "No. of flights landing in :" << city[i] << " = " << cnt << endl;
		cout << "Indegree = " << sum << endl; 
	}
}

int main()
{
	graph obj;
	int ch, q;
	cout << "1. Enter the details of network" << endl;
	cout << "2. Add a city to network" << endl;
	do
	{
		cout << "Enter your choice :" << endl;
		cin >> ch;
		switch(ch)
		{
			case 1:
				{
					obj.create_list();
					cout << "The Network is :" << endl;
					obj.show_list();
					cout << endl;
					break;
				}
			case 2:
				{
					obj.add_city();
					cout << "Appended Network is :" << endl;
					obj.show_list();
					cout << endl;
					break;
				}
			case 3:
				{
					obj.del_city();
					cout << "Network after deletion is :" << endl;
					obj.show_list();
					cout << endl;
					break;
				}
			case 4:
				{
					obj.outdegree();
					break;
				}
			case 5:
				{
					obj.indegree();
					break;
				}
		}
		cout << "Do you wish to continue?(1 for yes, 0 for no)" << endl;
		cin >> q;
	}while(q == 1);
	return 0;
}
