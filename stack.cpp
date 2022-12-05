#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack{
	int top;
	T* data;
	int capacity;
	int size;
public:
	Stack()
	{
		this->top = -1;
		this->size = 0;
		this->capacity = 5;
		this->data = new T[5];
	}

	void insert(T data)
	{
		int temp = size;
		if(++temp == capacity)
		{
			T* newData = new T[capacity*2];
			for(int i=0;i<this->size;i++)
			{
				newData[i] = this->data[i];
			}
			delete []this->data;
			this->data = newData;
			capacity = capacity*2;
		}
		this->data[++top] = data;
		size++;
	}

	void pop()
	{
		if(top == -1)
		{
			cout<<"Stack underflow"<<endl;

		}
		else
		{
			top--;
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

	void print()
	{
		for(int i=0;i<size;i++)
		{
			cout<<this->data[i]<<" ";

		}
		cout<<endl;
	}
	T topElement()
	{
		return data[top];
	}
};

bool balancedParanthesis(string a)
{
	Stack<char> s;
	for(int i=0;i<a.size();i++)
	{
		if(a[i] == '(' || a[i] == '{' || a[i] == '[')
		{
			s.insert(a[i]);
		}	
		else
		{
			if((a[i] == ')' && s.topElement() == '(') || (a[i] == '}' && s.topElement() == '{') || (a[i] == ']' && s.topElement() == '['))
			{
				s.pop();
			}
			else
			{
				s.insert(a[i]);
				break;
			}
		}

	}
	return s.isEmpty() ? true : false;
}

int priority(char a)
{
	if(a == '+' || a == '-')
	{
		return 1;
	}
	else if(a == '*' || a == '/')
	{
		return 2;
	}
	else if(a == '^')
	{
		return 3;
	}
	return 0;
}


string infixToPostfix(string a)
{
	Stack<int> s;
	string t;
	for(int i=0;i<a.size();i++)
	{
		if((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= '0' && a[i] <= '9'))
		{
			t+=a[i];
		}
		else if(a[i] == '(')
		{
			s.insert(a[i]);
		}
		else if(a[i] == ')')
		{
			while(s.topElement() != '(')
			{
				t+=s.topElement();
				s.pop();
			}
			s.pop();
		}
		else
		{
			while(!s.isEmpty() && priority(a[i]) <= priority(s.topElement()))
			{
				t+=s.topElement();
				s.pop();
			}
			s.insert(a[i]);
		}
	}
	while(!s.isEmpty())
	{
		t+=s.topElement();
		s.pop();
	}
	return t;
}

string infixToPrefix(string a)
{
	reverse(a.begin(), a.end());
	for(int i=0;i<a.size();i++)
	{
		if(a[i] == '(')
		{
			a[i] = ')';
		}
		else if(a[i] == ')')
		{
			a[i] = '(';
		}
	}
	string l = infixToPostfix(a);
	reverse(l.begin(), l.end());
	return l;


}


// int resolvePE(string a)
// {
// 	Stack<int> s;
// 	for(int i=0;i<a.size();i++)
// 	{
// 		if(a[i] == '+' || a[i] == '*' || a[i] == '-' || a[i] == '-')
// 		{
// 			int element1 = s.topElement();
// 			s.pop();
// 			int element2 = s.topElement();
// 			s.pop();
// 			if(a[i] == '+')
// 			{
// 				s.insert(element1 + element2);
// 			}
// 			else if(a[i] == '-')
// 			{
// 				s.insert(element1 - element2);
// 			}
// 			else if(a[i] == '*')
// 			{
// 				s.insert(element1 * element2);
// 			}
// 			else if(a[i] == '/')
// 			{
// 				s.insert(element1 / element2);
// 			}
// 		}
// 		else
// 		{
// 			s.insert(atoi(a[i].c_str()));
// 		}
// 	}
// 	return s.topElement();
// }

int main()
{
	string a;
	cin>>a;
	cout<<infixToPrefix(a);

}