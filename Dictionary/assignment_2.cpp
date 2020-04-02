#include<iostream>
#include<cstring>
using namespace std;

class Node
{
	private:
		string word;
		string meaning;
		Node *left, *right;
	public:
		friend class Dictionary;
};

class Dictionary
{
	public:	
		Node *root, *p;
		int count, found;
		string a, b, c, d;
		Dictionary()
		{
			root = NULL;
			p = NULL;
		}
		void insertword();
		void ascending();
		void inorder1(struct Node *);
		void descending();
		void inorder2(struct Node *);
		void search();
		Node *dict_search(string);
		void delword();
		void updateword();
		void comparisons();
};

void Dictionary::insertword()
{
	int flag;
	string x, y;
	cout << "Enter word :" << endl;
	cin >> x;
	cout << "Enter meaning :" << endl;
	cin >> y;
	Node *p = new Node;
	p->right = NULL;
	p->left = NULL;
	p->word = x;
	p->meaning = y;
	if(root == NULL)
	{
		root = p;
		cout << "Root is added!" << endl;
	}
	else
	{
		struct Node *q;
		q = root;
		flag = 0;
		while(flag != 1)
		{
			if(p->word < q->word)
			{
				if(q->left == NULL)
				{
					q->left = p;
					flag = 1;
					cout << p->word << " get added to left of " << q->word << endl;
				}
				else
				{
					q = q->left;
				}
			}
			else if(p->word > q->word)
			{
				if(q->right == NULL)
				{
					q->right = p;
					flag = 1;
					cout << p->word << " get added to right of " << q->word << endl;
				}
				else
				{
					q = q->right;
				}
			}
			else if(p->word == q->word)
			{
				cout << "Word is already present in the dctionary!" << endl;
				return;
			}
		}
	}
}

void Dictionary::ascending()
{
	if(root == NULL)
	{
		cout << "Tree is Empty!" << endl;
	}
	else
	{
		cout << "Displaying words in Ascending Order :" << endl;
		inorder1(root);
		cout << endl;
	}
}

void Dictionary::inorder1(struct Node *m)
{
	if(m != NULL)
	{
		inorder1(m->left);
		cout << m->word << "\t";
		inorder1(m->right);
	}
}

void Dictionary::descending()
{
	if(root == NULL)
	{
		cout << "TRee is Empty!" << endl;
	}
	else
	{
		cout << "DIsplaying words in Descending Order :" << endl;
		inorder2(root);
		cout << endl;
	}
}

void Dictionary::inorder2(struct Node *n)
{
	if(n != NULL)
	{
		inorder2(n->right);
		cout << n->word << "\t";
		inorder2(n->left);
	}
}

void Dictionary::search()
{
	Node *u;
	cout << "Enter word to be searched :" << endl;
	cin >> a;
	if(root == NULL)
	{
		cout << "Dictionary is Empty!" << endl;
		return;
	}
	u = dict_search(a);
	if(u == NULL)
	{
		cout << "Word not found!" << endl;
	}
	else
	{
		cout << "Word found!" << endl;
		cout << u->word << "\t" << u->meaning << endl;
	}
}

Node *Dictionary::dict_search(string j)
{
	found = 0;
	count = 0;
	struct Node *q1 = root;
	while(found != 1)
	{
		count++;
		if(j < q1->word)
		{
			if(q1->left == NULL)
			{
				return NULL;
			}
			else
			{
				q1 = q1->left;
			}
		}
		else if(j > q1->word)
		{
			if(q1->right == NULL)
			{
				return NULL;
			}
			else
			{
				q1 = q1->right;
			}
		}
		else
		{
			if(j.compare(q1->word) == 0)
			{
				found = 1;
				return q1;
			}
		}
	}
}

void Dictionary::delword()
{
	string k;
	cout << "Enter word you want to delete :" << endl;
	cin >> k;
	struct Node *w;
	w = dict_search(k);
	if(w == NULL)
	{
		cout << "Word cannot be deleted as it is not present in the Dictionary!" << endl;
	}
	else
	{
		struct Node *q2 = root;
		struct Node *p2 = root;
		while(1)
		{
			if(k < q2->word)
			{
				p2 = q2;
				q2 = q2->left;
			}
			else if(k > q2->word)
			{
				p2 = q2;
				q2 = q2->right;
			}
			else if(q2->left == NULL && q2->right == NULL)
			{
				if(p2->left == q2)
				{
					p2->left = NULL;
					delete q2;
					cout << "Node deleted successfully!" << endl;
					return;
				}
				else
				{
					p2->right = NULL;
					delete q2;
					cout << "Node deleted successfully!" << endl;
					return;
				}
			}
			else if(q2->left == NULL)
			{
				if(p2->right == q2)
				{
					p2->right = q2->right;
					delete q2;
					cout << "Node deleted successfully!" << endl;
					return;
				}
				else
				{
					p2->left = q2->right;
					delete q2;
					cout << "Node deleted successfully!" << endl;
					return;
				}
			}
			else if(q2->right == NULL)
			{
				if(p2->right == q2)
				{
					p2->right = q2->left;
					delete q2;
					cout << "Node deleted successfully!" << endl;
					return;
				}
				else
				{
					p2->left = q2->left;
					delete q2;
					cout << "Node deleted successfully!" << endl;
					return;
				}
			}
			else if(q2->left != NULL && q2->right != NULL)
			{
				Node *q3, *q4;
				q3 = q2->right;
				q4 = q2->right;
				while(q3->left != NULL)
				{
					q4 = q3;
					q3 = q3->left;
				}
				q2->word = q3->word;
				q2->meaning = q3->meaning;
				if(q3->left == NULL)
				{
					q2->right = q3->right;
					delete q3;
				}
				else
				{
					q4->left = q3->right;
					delete q3;
				}
				cout << "Node deleted successfully!" << endl;
				return;
			}
		}
	}
}

void Dictionary::updateword()
{
	cout << "Enter word to be updated :" << endl;
	cin >> b;
	if(root == NULL)
	{
		cout << "Dictionary is empty!" << endl;
		return;
	}
	struct Node *e;
	e = dict_search(b);
	if(e == NULL)
	{
		cout << "Word not found!" << endl;
	}
	else
	{
		cout << "Word found!" << endl;
		cout << "Enter updated meaning :" << endl;
		cin >> c;
		e->meaning = c;
	}
}

void Dictionary::comparisons()
{
	cout << "Maximum comparisons required are :" << endl;
	cout << count << endl;
}

int main()
{
	Dictionary d1, d2;
	int ch;
	do
	{
		cout << "Enter your choice" << endl;
		cout << "1. Insert a word in the Dictionary" << endl;
		cout << "2. Display words of Dictionary in Ascending Order" << endl;
		cout << "3. Display words of Dictionary in Descending Order" << endl;
		cout << "4. Search  a word in the Dictonary" << endl;
		cout << "5. Delete a word from the Dictionary" << endl;
		cout << "6. Update a word in the DIctionary" << endl;
		cout << "7. Calculate maximum comparisons" << endl;
		cout << "8. Copy Dictionary" << endl;
		cin >> ch;
		switch(ch)
		{
			case 1:
				d1.insertword();
				break;
			case 2:
				d1.ascending();
				break;
			case 3:
				d1.descending();
				break;
			case 4:
				d1.search();
				break;
			case 5:
				d1.delword();
				break;
			case 6:
				d1.updateword();
				break;
			case 7:
				d1.comparisons();
				break;
		}
	}while(ch != 9);
	return 0;
}
