/*
 * NAME:Shubham Chaudhari
 * ROLL NUMBER:2217
 * DATE CREATED:22 Feb 2018
 * DATE COMPLETED:
 */

#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

class node{
	string word;
	string meaning;
	node *left,*right;
public:
	node(){left=right=NULL;}
	node(string word,string meaning){
		this->word = word;
		this->meaning = meaning;
		left=right=NULL;
	}
	friend class avlTree;
};

class avlTree{
	node *root;
	int subtreeHeight(node*);
	void LLrotation(node*);
	void RRrotation(node*);
	void LRrotation(node*);
	void RLrotation(node*);

	bool nodeBalanceFactor(node*);
public:
	avlTree(){root=NULL;}
	node* createNode(string,string);
	void insertNode(string,string);
	void deleteNode(string);
	void update();
	int search(string);

	node* getRoot(){return root;}

	void ascendingOrder();
	void decendingOrder();
	void preOrder(node*);
};

int avlTree::subtreeHeight(node *temp){
	 if (temp==NULL)
	       return 0;
	   else{
	       int lHeight = subtreeHeight(temp->left);
	       int rHeight = subtreeHeight(temp->right);

	       if (lHeight > rHeight)
	           return(lHeight+1);
	       else return(rHeight+1);
	   }
}

bool avlTree::nodeBalanceFactor(node *temp){
	int lHeight = subtreeHeight(temp->left);
	int rHeight = subtreeHeight(temp->right);

	if(lHeight==rHeight || lHeight-rHeight==1 || rHeight-lHeight==1)
		return true;
	return false;
}

node* avlTree::createNode(string word,string meaning){
	node *temp = new node(word,meaning);
	if(temp==NULL)
		cout<<"Node not created"<<endl;
	return temp;
}

void avlTree::insertNode(string word,string meaning){
	node *temp=new node;
	node *trav = new node;
	node *parent = new node;

	if(!temp){
	    cout<<"Error!Node Not Created"<<endl;
	    return;
	}
	else{
	    temp->word = word;
	    temp->meaning = meaning;
	    temp->left = NULL;
	    temp->right = NULL;
	}

	stack<node*> mStack;

	if(root==NULL)
	    root = temp;
	else{
	    trav = root;
	    while(trav!=NULL){
	    	mStack.push(trav);
	        if(trav->word<word){
	            parent = trav;
	            trav = trav->right;
	        }
	        else{
	            parent = trav;
	            trav = trav->left;
	        }
	    }
	    if(parent->word<word)
	        parent->right = temp;
	    else
	        parent->left = temp;
	}

	bool isBalanced = true;

	while(!mStack.empty()){
		temp = mStack.top();
		mStack.pop();
		parent = temp;
		isBalanced = nodeBalanceFactor(temp);
		if(!isBalanced){
			if(temp->word<word){
				temp = temp->right;
				if(temp->word<word)
					LLrotation(parent);
				else
					RLrotation(parent);
			}
			else{
				temp = temp->left;
				if(temp->word<word)
					LRrotation(parent);
				else
					RRrotation(parent);
			}
		}
	}
}

void avlTree::LLrotation(node *grandParent){
	node *parent = grandParent->right;
	node *child = parent->right;

	string temp;
	temp = grandParent->word;
	grandParent->word = parent->word;
	parent->word = temp;

	temp = grandParent->meaning;
	grandParent->meaning = parent->meaning;
	parent->meaning = temp;

	grandParent->right = child;
	parent->right = parent->left;
	parent->left = grandParent->left;
	grandParent->left = parent;
}
void avlTree::LRrotation(node *grandParent){
	node *parent = grandParent->left;
	node *child = parent->right;

	string temp;
	temp = grandParent->word;
	grandParent->word = child->word;
	child->word = temp;

	temp = grandParent->meaning;
	grandParent->meaning = child->meaning;
	child->meaning = temp;

	parent->right = child->left;
	child->left = child->right;
	child->right = grandParent->right;
	grandParent->right = child;
}
void avlTree::RLrotation(node *grandParent){
	node *parent = grandParent->right;
	node *child = parent->left;

	string temp;
	temp = grandParent->word;
	grandParent->word = child->word;
	child->word = temp;

	temp = grandParent->meaning;
	grandParent->meaning = child->meaning;
	child->meaning = temp;

	parent->left = child->right;
	child->right = child->left;
	child->left = grandParent->left;
	grandParent->left = child;
}

void avlTree::RRrotation(node *grandParent){
	node *parent = grandParent->left;
	node *child = parent->left;

	string temp;
	temp = grandParent->word;
	grandParent->word = parent->word;
	parent->word = temp;

	temp = grandParent->meaning;
	grandParent->meaning = parent->meaning;
	parent->meaning = temp;

	grandParent->left = child;
	parent->left = parent->right;
	parent->right = grandParent->right;
	grandParent->right = parent;

}

void avlTree::ascendingOrder(){
	node *current = root;
	stack<node*> mStack;

    while(true){
    	if(current!=NULL){
	        mStack.push(current);
	        current = current->left;
	    }
	    else{
            if(!mStack.empty()){
            	current = mStack.top();
	            mStack.pop();
	            cout<<current->word<< "--->"<<current->meaning<<endl;
	            current = current->right;
            }
	        else
	            break;
        }
    }
}

void avlTree::decendingOrder(){
	node *current = root;
	stack<node*> mStack;

    while(true){
    	if(current!=NULL){
	        mStack.push(current);
	        current = current->right;
	    }
	    else{
            if(!mStack.empty()){
            	current = mStack.top();
	            mStack.pop();
	            cout<<current->word<< "--->"<<current->meaning<<endl;
	            current = current->left;
            }
	        else
	            break;
        }
    }
}

int avlTree::search(string word){
	node *temp=root;
	bool flag =false;
	int i=0;
	while(temp!=NULL){
		if(word<temp->word){
			temp=temp->left;
			i++;
		}
		else if(word>temp->word){
			temp=temp->right;
			i++;
		}
		else{
			flag=true;
			break;
		}
	}
	if(flag)
		return i+1;
	else
		return -1;
}

void avlTree::update(){
	string word,meaning;
	cout<<"Enter word: :";
	getline(cin,word);

	node *temp=root;
	while(temp!=NULL){
		if(word<temp->word)
			temp=temp->left;
		else if(word>temp->word)
			temp=temp->right;
		else{
			break;
		}
	}
	if(temp==NULL){
		cout<<"The word does not exists in the dictionary."<<endl;
		char choice;
		cout<<"Do you want to add the word in the dictionary? ";
		cin>>choice;
		cout<<"Enter meaning of "<<word<<": :";
		getline(cin,meaning);
		if(choice=='y' || choice=='Y')
			insertNode(word,meaning);
	}
	else{
		cout<<"Enter new meaning: :";
		getline(cin,meaning);
		temp->meaning=meaning;
	}
}

void avlTree::deleteNode(string word){
	node *temp=root;
	node *previous;
	bool flag =false;
	bool position=false;
	while(temp!=NULL){
		if(word<temp->word){
			previous=temp;
			temp=temp->left;
			position = false;
		}
		else if(word>temp->word){
			previous=temp;
			temp=temp->right;
			position = true;
		}
		else{
			flag=true;
			break;
		}
	}

	if(!flag)
		cout<<"Node not present.";
	else{
		if(temp==root){
			flag=false;
			node *temp1 = new node;
			temp1=temp;
			temp=temp->right;
			while(temp->left!=NULL){
				temp1 = temp;
				temp=temp->left;
				flag=true;
			}
			root->word = temp->word;
			root->meaning = temp->meaning;
			if(flag)
				temp1->left=NULL;
			else
				root->right=NULL;
			delete temp;

		}
		else if(temp->right==NULL && temp->left==NULL){
			if(position)
				previous->right=NULL;
			else
				previous->left=NULL;
			delete temp;
		}
		else if(temp->right!=NULL && temp->left!=NULL){
			node *temp1 = new node;
			previous=temp;
			temp1=temp;
			temp=temp->right;
			while(temp->left!=NULL){
				temp1 = temp;
				temp=temp->left;
			}
			previous->word = temp->word;
			previous->meaning = temp->meaning;
			temp1->left=NULL;
			delete temp;
		}
		else{
			if(temp->left==NULL){
				if(position)
					previous->right = temp->right;
				else
					previous->left = temp->right;
			}
			else{
				if(position)
					previous->right = temp->left;
				else
					previous->left = temp->left;
			}
			delete temp;
		}
	}
}

void avlTree::preOrder(node *temp){
	if(temp==NULL)
		return;
	cout<<temp->word;
	preOrder(temp->left);
	preOrder(temp->right);
}

int main(){
	avlTree avl;
	string word,meaning;
	int choice,comp;

	cout<<"1.Insert Word\n2.Display in ascending order\n3.Display in descending Order\n4.Search word\n5.Update word\n6.Delete word\n7.Copy Tree\n8.Exit"<<endl;
	do{
		cout<<"Enter the operation to be performed: :";
		cin>>choice;
		cin.ignore();
		switch(choice){
		case 1:
			cout<<"Enter the word: :";
			getline(cin,word);
			cout<<"Enter meaning of "<<word<<": :";
			getline(cin,meaning);
			avl.insertNode(word,meaning);
			break;

		case 2:
			avl.ascendingOrder();
			break;

		case 3:
			avl.decendingOrder();
			break;

		case 4:
			cout<<"Enter the word to be searched: :";
			getline(cin,word);
			comp = avl.search(word);
			if(comp==-1)
				cout<<word<<" is not present in the dictionary"<<endl;
			else
				cout<<"Word found.Number of comparisons required is "<<comp<<endl;
			break;

		case 5:
			avl.update();
			break;

		case 6:
			cout<<"Enter the word to be deleted: :";
			getline(cin,word);
			avl.deleteNode(word);
			break;

			default:
				choice=-1;
				break;
			}
		}while(choice!=-1);

	avl.preOrder(avl.getRoot());

	return 0;
}

