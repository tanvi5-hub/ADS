#include<iostream>
using namespace std;
void showChoices();

class Node
{
	private:
		int data;
		Node *left;
		Node *right;
	public:	
		Node(int x)
		{
			data = x;
			left = NULL;
			right = NULL;
		}
		friend class BinTree;
};

class Stack
{
	private:
		Node *data[30];
		int top;
	public:	
		Stack()
		{
			top = -1;
		}
		bool isFull()
		{
			if(top == 29)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool isEmpty()
		{
			if(top == -1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void push(Node *p)
		{
			if(!isFull())
			{
				top++;
				data[top] = p;
			}
		}
		Node *pop()
		{
			Node *p = data[top];
			if(!isEmpty())
			{
				top--;
			}
			return p;
		}
};

class BinTree
{
	private:
		Node *root;		
	public:
		int count1 = 0;
		void create()
		{
			root = insert();
		}
		Node *insert();
		void preorder()
		{
			pre_rec(root);
		}
		void pre_rec(Node *);
		void pre_nonrec()
		{
			Stack s;
			Node *p = root;
			while(p != NULL)
			{
				cout << p->data << " ";
				s.push(p);
				p = p->left;
			}
			while(!s.isEmpty())
			{
				p = s.pop();
				p = p->right;
				while(p != NULL)
				{
					cout << p->data << " ";
					s.push(p);
					p = p->left;
				}
			}
		}
		void inorder()
		{
			in_rec(root);
		}
		void in_rec(Node *);
		void in_nonrec()
		{
			Stack s;
			Node *p = root;
			while(p != NULL)
			{
				s.push(p);
				p = p->left;
			}
			while(!s.isEmpty())
			{
				p = s.pop();
				cout << p->data << " ";
				p = p->right;
				while(p != NULL)
				{
					s.push(p);
					p = p->left;
				}
			}
		}
		void postorder()
		{
			post_rec(root);
		}
		void post_rec(Node *);
		void post_nonrec()
		{
			Stack s, s1;
			Node *p = root;
			s.push(p);
			while(!s.isEmpty())
			{
				p = s.pop();
				s1.push(p);
				if(p->left != NULL)
				{
					s.push(p->left);
				}
				if(p->right != NULL)
				{
					s.push(p->right);
				}
			}
			while(!s1.isEmpty())
			{
				p = s1.pop();
				cout << p->data << " ";
			}
			cout << endl;
		}
		void height()
		{
			cout << "Height of Tree is " << height_rec(root) << endl;
		}
		int height_rec(Node *T)
		{
			int h1, h2;
			if(T == NULL)
			{
				return 0;
			}
			else
			{
				h1 = height_rec(T->left);
				h2 = height_rec(T->right);
				return (1 + max(h1, h2));
			}
		}
		int max(int a, int b)
		{
			if(a > b)
			{
				return a;
			}
			else
			{
				return b;
			}
		}
		
		void leaf()
		{
			int count = leaf_rec(root);
			cout << "Total no. of leaf nodes :" << count << endl;
		}
		int leaf_rec(Node *T)
		{
			if(T == NULL)
			{
				return 0;
			}
			if(T->left == NULL && T->right == NULL)
			{
				return 1;
			}
			return (leaf_rec(T->left) + leaf_rec(T->right));
		}
		
		void interior()
		{
			int count = leaf_rec(root);
			cout << "Total no. of nodes are :" << count1 << endl;
			cout << "Interior Nodes are :" << count1 - count << endl;
		}
		
		void mirror()
		{
			mirr_rec(root);
		}
		void mirr_rec(Node *T)
		{
			Node *temp;
			if(T == NULL)
			{
				return;
			}
			mirr_rec(T->left);
			mirr_rec(T->right);
			temp = T->left;
			T->left = T->right;
			T->right = temp;
		}
		
		void del()
		{
			del_node(root);
			cout << "Total no. of nodes now are :" << count1 << endl;
		}
		void del_node(Node *);
};

Node *BinTree::insert()
{
	Node *p;
	int x;
	cout << "Enter data(-1 for no data)" << endl;
	cin >> x;
	if(x == -1)
	{
		return NULL;
	}
	else
	{
		p = new Node(x);
		cout << "ENter to the left of " << x << endl;
		p->left = insert();
		cout << "ENterto the right of " << x << endl;
		p->right = insert();
		count1++;
	}
	return p;
}

void BinTree::pre_rec(Node *T)
{
	if(T != NULL)
	{
		cout << T->data << " ";
		pre_rec(T->left);
		pre_rec(T->right);
	}
}

void BinTree::in_rec(Node *T)
{
	if(T != NULL)
	{
		in_rec(T->left);
		cout << T->data << " ";
		in_rec(T->right);
	}
}

void BinTree::post_rec(Node *T)
{
	if(T != NULL)
	{
		post_rec(T->left);
		post_rec(T->right);
		cout << T->data << " ";
	}
}

void BinTree::del_node(Node *T)
{
	if(T != NULL)
	{
		del_node(T->left);
		del_node(T->right);
		count1 = count1 - 1;
		delete T;
	}
}

int main()
{
	BinTree obj;
	int ch, q;
	showChoices();
	do
	{
		cout << "Enter your choice :" << endl;
		cin >> ch;
		switch(ch)
		{
			case 1:
				{
					obj.create();
					break;
				}
			case 2:
				{
					obj.preorder();
					break;
				}
			case 3:
				{
					obj.pre_nonrec();
					break;
				}
			case 4:
				{
					obj.inorder();
					break;
				}
			case 5:
				{
					obj.in_nonrec();
					break;
				}
			case 6:
				{
					obj.postorder();
					break;
				}
			case 7:
				{
					obj.post_nonrec();
					break;
				}
			case 8:
				{
					obj.height();
					break;
				}
			case 9:
				{
					obj.leaf();
					break;
				}
			case 10:
				{
					obj.interior();
					break;
				}
			case 11:
				{
					obj.mirror();
					cout << "Mirror Image" << endl;
					obj.preorder();
					break;
				}
			case 12:
				{
					obj.del();
					cout << "All Nodes are deleted!" << endl;
					break;
				}
			case 13:
				{
					BinTree t;
					t = obj;
					cout << "Copied Tree :" << endl;
					t.pre_nonrec();
					break;o
				}
		}
		cout << "Do you wish to continue?(1 for yes, 0 for no)" << endl;
		cin >> q;
	}while(q == 1);
	return 0;
}

void showChoices()
{
	cout << "1. Create a Binary Tree" << endl;
	cout << "2. PReorder(Recursive)" << endl;
	cout << "3. PReorder(Non-Recursive)" << endl;
	cout << "4. Inorder(Recursive)" << endl;
	cout << "5. Inorder(Non-Recursive)" << endl;
	cout << "6. Postorder(Recursive)" << endl;
	cout << "7. Postorder(Non-Recursive)" << endl;
	cout << "8. Height" << endl;
	cout << "9. Leaf Nodes" << endl;
	cout << "10. Interior Nodes" <<endl;
	cout << "11. Mirror Image" << endl;
	cout << "12. Delete All Nodes" << endl;
	cout << "13. Copy Binary Tree" << endl;
}
