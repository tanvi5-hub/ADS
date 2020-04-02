//============================================================================
// Name        : ass5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
# define $ 9999
using namespace std;

class edge_list{
public:
	string source;
	string destination;
	int cost;

	void edge(string a, string b, int x)
	{
		source=a;
		destination=b;
		cost=x;
	}
};

class graph{
	int G[20][20];
	int cost[20][20];
	string city[20];
	edge_list el1[20],el2[20];
	int ne,n,n2;
	int visited[20],from[20],dist[20];
	int res[20][20];
public:
	graph()
	{
		ne=n2=0;
		cout<<"Enter the number of cities to be represented on network"<<endl;
		cin>>n;

		for(int i=0;i<n;i++)
		{
			city[i]=" ";
			for(int j=0;j<n;j++)
			{
				G[i][j]=0;
				cost[i][j]=0;
			}

		}
	}
	//CREATION OF UNDIRECTED GRAPH
	void read_mat()
	{
		int o;
		int k=0;
		cout<<"Enter the cities in network"<<endl;
		for(int i=0;i<n;i++)
		{
			cin>>city[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				cout<<"Is there a connection between "<<city[i]<<" and "<<city[j]<<" (1 for yes/0 for no)?"<<endl;
				cin>>o;
				if(o==1)
				{
					cout<<"Enter the cost"<<endl;
					cin>>G[i][j];
					G[j][i]=G[i][j];
					el1[k].edge(city[i],city[j],G[i][j]);
					k++;
					ne++;
				}
				if(o==0)
				{
					G[i][j]=G[j][i]=0;
				}

			}
		}
		//CREATION OF COST MATRIX
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(G[i][j]==0)
				{
					cost[i][j]=$;
				}
				else
				{
					cost[i][j]=G[i][j];
				}
				res[i][j]=0;
			}
		}
	}
	void show_mat()
	{
		for(int i=0;i<n;i++)
		{
			cout<<" "<<city[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<city[i]<<" ";
			for(int j=0;j<n;j++)
			{
				cout<<G[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	void show_list()
	{
		cout<<"Total number of edges are "<<ne <<endl;
		for(int i=0;i<ne;i++)
		{
			cout<<el1[i].source<<" "<<el1[i].destination<<" "<<el1[i].cost<<endl;
		}
	}
	//KRUSKAL'S ALGORITHM
	void kruskals()
	{ int k=0;
		int component[20];
		//sorting the list
		for(int i=0;i<ne;i++)
		{
			for(int j=0;j<ne;j++)
			{
				if(el1[j].cost>el1[i].cost)
				{
					edge_list temp=el1[j];
					el1[j]=el1[i];
					el1[i]=temp;
				}
			}
		}
		cout<<"The sorted list is "<<endl;
		show_list();
		//cout<<"hi";
		for(int i=0;i<n;i++)
		{
			component[i]=i;
		}
		int no_of_edges=n-1;
		int i=0;
		//cout<<"hi";
		while(no_of_edges>0)
		{
			//cout<<"hi";
			int v,u;
			string u1,v1;
			int w;
			u1=el1[i].source;
			v1=el1[i].destination;
			w=el1[i].cost;
			for(int p=0;p<n;p++)
			{
				if(city[p]==u1)
				{
					 u=p;
				}
			}
			for(int p=0;p<n;p++)
			{
				if(city[p]==v1)
				{
					 v=p;
				}
			}

			int cou=component[u];
			int cov=component[v];

			if(cou!=cov)
			{
				el2[k].source=u1;
				el2[k].destination=v1;
				el2[k].cost=w;
				n2++;
				k++;

				for(int j=0;j<n;j++)
				{
					if(component[j]==cou)
					{
						component[j]=cov;
					}
				}
			}
			i++;
			no_of_edges--;
		}
		cout<<"The network with minimum cost is"<<endl;
		int sum=0;
		for(int k=0;k<n2;k++)
		{
			cout<<el2[k].source<<" "<<el2[k].destination<<" "<<el2[k].cost<<endl;
			sum=sum+el2[k].cost;
		}
		cout<<"The cost is: "<<sum<<endl;
	}
	//PRIMS ALGORITHM
	void prims()
	{
		int v,u;
		//Initializing the arrays
		for(int i=0;i<n;i++)
		{
			visited[i]=0;
			dist[i]=cost[0][i];
			from[i]=0;
		}
		//Visiting first vertex
		visited[0]=1;
		int no_of_edges=n-1;
		while(no_of_edges>=0)
		{
			//Finding vertex with minimum distance and unvisited
			int min=$;
			for(int i=0;i<n;i++)
			{
				if(visited[i]==0 && dist[i]<min)
				{
					min=dist[i];
					v=i;
				}
			}

			u=from[v];
			res[u][v]=cost[u][v];
			res[v][u]=cost[u][v];

			//Updating the from and distance array
			for(int i=0;i<n;i++)
			{
				if(visited[i]==0 && dist[i]>cost[v][i])
				{
					dist[i]=cost[v][i];
					from[i]=v;
				}
			}
			no_of_edges--;
		}
		//Printing the resultant matrix
		cout<<"The resultant minimum cost matrix is: "<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<" "<<city[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<city[i]<<" ";
			for(int j=0;j<n;j++)
			{
				cout<<res[i][j]<<" ";
			}
				cout<<endl;
		}
		int sum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				sum=sum+res[i][j];
			}
		}
		cout<<"The minimum cost is: "<<sum<<endl;
	}

};

int main()
{
	graph obj;
	int ch;
	int q=0;
	cout<<"----------MENU----------"<<endl;
	cout<<"1.Enter the details of network"<<endl;
	cout<<"2.Kruskal's algorithm"<<endl;
	cout<<"3.Prims algorithm"<<endl;
	do{
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
		{
			obj.read_mat();
			cout<<"The matrix created is"<<endl;
			obj.show_mat();
			cout<<endl;
			cout<<"The edge_list created is"<<endl;
			obj.show_list();
			break;


		}
		case 2:
		{
			obj.kruskals();
			break;
		}
		case 3:
		{
			obj.prims();
			break;
		}
		}
		cout<<"Do you want to continue(1 for yes/0 for no)?"<<endl;
		cin>>q;
	}while(q==1);
	return 0;
}
