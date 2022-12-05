# include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;

	}
};

class dNode{
public:
	int data;
	Node* prev;
	Node* next;
	Node(int data)
	{
		this->data = data;
		this->prev = NULL;
		this->next = NULL:
	}
};

dNode* takeInputd()
{
	dNode* head = NULL;
	dNode* tail = NULL;
	int data;
	cin>>data;
	while(data != -1)
	{
		if(head == NULL)
		{
			dNode* n = new dNode(data);
			head = n;
			tail = n;
			n->prev = NULL;
		}
		else
		{
			dNode* n = new dNode(data);
			n->prev = head;
			head->next = n;
			head = n;
		}
		cin>>data;
	}

}


Node* takeInput() // -> Take input at the tail of the linked list
{
	Node* head = NULL;
	Node* tail = NULL;
	int data;
	cin>>data;
	while(data != -1)
	{
		Node* n = new Node(data);
		if(head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			tail->next = n;
			tail = n;
			
		}
		cin>>data;
	}
	return head;
}

Node* takeInput2()
{
	Node* head = NULL;
	Node* tail = NULL;
	int data;
	cin>>data;
	while(data != -1)
	{
		Node* n = new Node(data);
		if(head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			n->next = head;
			head = n;
		}
		cin>>data;
	}
	return head;
}

void print(Node* head)
{
	while(head != NULL)
	{
		cout<<head->data;
		head = head->next;
	}
	cout<<endl;

}

Node* InsertNode(Node* head, int data, int position)
{
	int count = 0;
	Node* temp = head;
	while(temp != NULL)
	{
		if(count == position - 1)
		{
			Node* n = new Node(data);
			Node* flag = temp->next;
			temp->next = n;
			n->next = flag;
			break;
		}
		temp = temp->next;
		count++;
	}
	return head;
}

Node* deleteNode(Node* head, int position)
{
	Node* temp = head;
	int count = 0;
	if(!head) return NULL;
	if(position < 0) return head;
	if(position == 0)
	{
		Node* newHead = temp->next;
		temp->next = NULL;
		delete temp;
		return newHead;
	}
	while(head != NULL)
	{
		if(count == position - 1)
		{
			if(temp && temp->next)
			{
			Node* flag = temp->next->next;
			Node* curr = temp->next;
			curr->next = NULL;
			temp->next = flag;
			delete curr;
			return head;
			}

		}
		temp = temp->next;
		count++;
	}
	return head;
}

Node* reverse(Node* head)
{
	Node* temp = head;
	Node* prev = NULL;
	while(temp != NULL)
	{
		Node* n = temp->next;
		temp->next = prev;
		prev = temp;
		temp = n;
	}
	return prev;
}


int main()
{
	Node* head = takeInput();
	print(head);
	Node* temp = InsertNode(head, 100, 2);
	print(temp);
	head = deleteNode(head,6);
	print(head);
	head = reverse(head);
	print(head);

}