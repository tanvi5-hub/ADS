#include<iostream>
#define MAX 50
using namespace std;

template<class T>
class SET
{
	private:
		T data[MAX];
		int n;
	public:
		
		SET()
		{
			n = -1;
		}
		
		void input(int num) 
		{
			T element;
			
			for(int i = 0; i < num; i++) 
			{
				cout << "Enter element " << i + 1 << ": " << endl;
				cin >> element;
				insert(element); 
			}	
		}	
		
		int insert(T element)
		{
			if(n >= MAX) 
			{
				cout << "OVERFLOW! SET is FULL!" << endl;
				return 0;
			}
			
			data[++n] = element;
			return 1;
		}
		
		int remove(T element)
		{
			if(n == -1)
			{
				cout << "UNDERFLOW! SET IS EMPTY!" << endl;
				return 0;
			}
			
			for(int i = 0; i < n; i++)
			{
				if(data[i] == element)
				{
					for(int j = i; j < n; j++)
					{
						data[j] = data[j + 1];
					}
					
					n--;
					return 1;
				}
			}
			return 0;
		}
		
		int contains(T element)
		{
			for(int i = 0; i <= n; i++)
			{
				if(data[i] == element)
				{
					return 1;
				}
			}
			return 0;
		}
		
		int size()
		{
			return n + 1;
		}
		
		SET<T> intersection(SET<T> s1, SET<T> s2)
		{
			SET<T> s3;
			
			for(int i = 0; i <= s1.n; i++)
			{
				for(int j = 0; j <= s2.n; j++)
				{
					if(s1.data[i] == s2.data[j])
					{
						s3.insert(s1.data[i]);
						break;
					}
				}
			}
			return s3;
		}
		
		void print()
		{
			for(int i = 0; i <= n; i++)
			{
				cout << data[i] << " ";
			}
		}
		
		SET<T> unionS(SET<T> s1, SET<T> s2)
		{
			SET<T> s3;
			int flag = 0;
			
			for(int i = 0; i <= s1.n; i++)
			{
				s3.insert(s1.data[i]);
			}
			
			for(int j = 0; j <= s2.n; j++)
			{
				flag = 0;
				for(int i = 0; i <= s1.n; i++)
				{
					if(s1.data[i] == s2.data[j])
					{
						flag = 1;
						break;
					}
				}
				
				if(flag == 0)
				{
					s3.insert(s2.data[j]);
				}
			}
			
			return s3;
		}
		
		SET<T> difference(SET<T> s1, SET<T> s2)
		{
			SET<T> s3;
			int flag = 0;
			
			for(int i = 0; i <= s1.n; i++)
			{
				for(int j = 0; j <= s2.n; j++)
				{
					if(s1.data[i] == s2.data[j])
					{
						flag = 1;
						break;
					}
					
					else
					{
						flag = 0;
					}
				}
				
				if(flag == 0)
				{
					s3.insert(s1.data[i]);
				}
			}
			return s3;
		}
		
		int subset(SET<T> s2)
		{
			int count = 0;
			int size = s2.size();
			
			for(int i = 0; i <= n; i++)
			{
				for(int j = 0; j <= s2.n; j++)
				{
					if(data[i] == s2.data[j])
					{
						count++;
						break;
					}
				}
			}
			
			if(count == size)
			{
				return 1;
			}
			
			return 0;
		}
};

int main()
{
	SET <int> s1, s2, s3;
	int ch, ele;
	
	cout << "Enter no. of elements in S1 :" << endl;
	cin >> ele;
	s1.input(ele);
	
	cout << "Enter no. of elements in S2 :" << endl;
	cin >> ele;
	s2.input(ele);
	
	do
	{
		
		cout << "SET OPERATIONS" << endl << endl;
		cout << "1. Insert in SET 1" << endl;
		cout << "2. Insert in SET 2" << endl;
		cout << "3. Remove from SET 1" << endl;
		cout << "4. Remove from SET 2" << endl;
		cout << "5. Search in SET 1" << endl;
		cout << "6. Search in SET 2" << endl;
		cout << "7. Size of SETS" << endl;
		cout << "8. Intersection" << endl;
		cout << "9. Union" << endl;
		cout << "10. Difference (s1 - s2)" << endl;
		cout << "11. Check if Subset (s1)" << endl;
		
		cin >> ch;
		
		switch(ch)
		{
			case 1:
				cout << "Enter Element in SET 1 :" << endl;
				cin >> ele;
				
				if(s1.insert(ele))
				{
					cout << ele << " inserted!" << endl;
				}
				
				else
				{
					cout << "Insertion Failed!" << endl;
				}
				break;
				
			case 2:
				cout << "Enter Element in SET 2 :" << endl;
				cin >> ele;
				
				if(s2.insert(ele))
				{
					cout << ele << " inserted!" << endl;
				}
				
				else
				{
					cout << "Insertion Failed!" << endl;
				}
				break;
				
			case 3:
				cout << "Enter Element to be removed from SET 1 :" << endl;
				cin >> ele;
				
				if(s1.remove(ele))
				{
					cout << ele << " removed!" << endl;
				}
				
				else
				{
					cout << "Deletion Failed!" << endl;
				}
				break;
				
			case 4:
				cout << "Enter Element to be removed from SET 2 :" << endl;
				cin >> ele;
				
				if(s2.remove(ele))
				{
					cout << ele << " removed!" << endl;
				}
				
				else
				{
					cout << "Deletion Failed!" << endl;
				}
				break;
				
			case 5:
				cout << "Enter Element to be searched in SET 1 :" << endl;
				cin >> ele;
				
				if(s1.contains(ele))
				{
					cout << ele << " is present!" << endl;
				}
				
				else
				{
					cout << ele << " is not present!" << endl;
				}
				break;
				
			case 6:
				cout << "Enter Element to be searched in SET 2 :" << endl;
				cin >> ele;
				
				if(s2.contains(ele))
				{
					cout << ele << " is present!" << endl;
				}
				
				else
				{
					cout << ele << " is not present!" << endl;
				}
				break;
				
			case 7:
				cout << "Size of SET 1 :" << s1.size() << endl;
				cout << "Size of SET 2 :" << s2.size() << endl;
				break;
				
			case 8:
				s3 = s1.intersection(s1, s2);
				
				cout << "SET 1 Elements :" << endl;
				s1.print();
				
				cout << "SET 2 Elements :" << endl;
				s2.print();
				
				cout << "INTERSECTION :" << endl;
				s3.print();
				
				break;
				
			case 9:
				s3 = s1.unionS(s1, s2);
				
				cout << "SET 1 Elements :" << endl;
				s1.print();
				
				cout << "SET 2 Elements :" << endl;
				s2.print();
				
				cout << "UNION :" << endl;
				s3.print();
				
				break;
				
			case 10:
				s3 = s1.difference(s1, s2);
				
				cout << "SET 1 Elements :" << endl;
				s1.print();
				
				cout << "SET 2 Elements :" << endl;
				s2.print();
				
				cout << "DIFFERENCE :" << endl;
				s3.print();
				
				break;
				
			case 11:
				if(s1.subset(s2))
				{
					cout << "SET 2 is SUBSET of S1!" << endl;
				}
				
				else
				{
					cout << "NOT A SUBSET!" << endl;
				}
				
				break;
		}
		
	}while(ch != 0);
	
	return 0;
}
