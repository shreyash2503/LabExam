# include <bits/stdc++.h>
using namespace std;
class BTNode{
public:
	int data;
	BTNode* left;
	BTNode* right;
	BTNode(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	~BTNode()
	{
		delete this->left;
		delete this->right;
	}
};

BTNode* takeInput()
{
	int data;
	queue<BTNode*> q;
	cout<<"Enter the root data::";
	cin>>data;
	BTNode* root = new BTNode(data);
	q.push(root);
	while(!q.empty())
	{
		int left;
		int right;
		BTNode* temp = q.front();
		q.pop();
		cout<<"Enter the left Node data for "<<temp->data<<"::";
		cin>>left;
		if(left != -1)
		{
			temp->left = new BTNode(left);
			q.push(temp->left);
		}
		cout<<"Enter the right Node data for "<<temp->data<<"::";
		cin>>right;
		if(right != -1)
		{
			temp->right = new BTNode(right);
			q.push(temp->right);
		}

	}
	return root;

}

void printBT(BTNode* root)
{
	queue<BTNode*> q;
	q.push(root);
	while(!q.empty())
	{
		BTNode* temp = q.front();
		cout<<temp->data<<" ";
		if(temp->left)
		{
			q.push(temp->left);
		}
		if(temp->right)
		{
			q.push(temp->right);
		}
		q.pop();
	}

}

void inOrderS(BTNode* root)
{
	BTNode* temp = root;
	stack<BTNode*> s;
	while(temp != NULL || !s.empty())
	{
		while(temp != NULL)
		{
			s.push(temp);
			temp = temp->left;

		}
		temp = s.top();
		cout<<temp->data<<" ";
		s.pop();
		temp = temp->right;

	}
}

void preOrderS(BTNode* root)
{
	BTNode* temp = root;
	stack<BTNode*> s;
	while(temp != NULL || !s.empty())
	{
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			if(temp->right)
			{
				s.push(temp->right);
			}
			temp = temp->left;
		}
		if(!s.empty())
		{
			temp = s.top();
			s.pop();
		}
	}
	cout<<endl;
}

void postOrderS(BTNode* root)
{
	BTNode* temp = root;
	stack<BTNode*> s;
	BTNode* pre = NULL;
	while(temp != NULL || !s.empty())
	{
		if(temp != NULL)
		{
			s.push(temp);
			temp = temp->left;
		}
		else
		{
			temp = s.top();
			if(temp->right == NULL || temp->right == pre)
			{
				cout<<temp->data<<" ";
				pre = temp;
				temp = NULL;
				s.pop();
			}
			else
			{
				temp = temp->right;
			}
		}
	}
	cout<<endl;
}
int HeightOfBinaryTree(BTNode* root)
{
	if(!root) return 0;

	return max(1+HeightOfBinaryTree(root->left), 1+HeightOfBinaryTree(root->right));
}

int fibonacciSearch(int a[], int n, int key)
{
	int fibMm2 = 0;
	int fibMm1 = 1;
	int fib = fibMm1 + fibMm2;

	while(fib < n)
	{
		fibMm2 = fibMm1;
		fibMm1 = fib;
		fib = fibMm1 + fibMm2;
	}
	int offset = -1;
	while(1)
	{
		int i = min(fibMm2+offset, n-1);
		if(a[i] < key)
		{
			fib = fibMm1;
			fibMm1 = fibMm2;
			fibMm2 = fib - fibMm1;
			offset = i;
		}
		if(a[i] > key)
		{
			fib = fibMm1;
			fibMm1 = fibMm2;
			fibMm2 = fib - fibMm1;
		}
		if(a[i] == key)
		{
			return i<p></p>;
		}
	}
	if(fibMm1 && a[offset+1] == key)
	{
		return offset+1;
	}
	return -1;
}




int main()
{

	BTNode* root = takeInput();
	printBT(root);
	inOrderS(root);
	preOrderS(root);
	postOrderS(root);

}