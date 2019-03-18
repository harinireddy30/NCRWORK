#include<iostream>
using namespace std;
template<class T>
class stack
{
	int top;
	T *arr;
	int size;
public:
	stack()
	{
		top = -1;
		size = 0;
		arr = NULL;
	}
	stack(int x)
	{
		top = -1;
		size = x;
		arr = new T[x];
	}
	void push(T x)
	{
			if (top == size - 1)
			{
				cout << "stack overflow"<<endl;
			}
			else
			    arr[++top] = x;
	}
	T pop()
	{
			if (top == -1)
			{
				cout << "stack overflow"<<endl;
			}
			else
		    	return arr[top--];
	}
	int peek()
	{
		T x = (T)-1;
		if (!IsEmpty())
		{
			x=arr[top --];
			return x;
		}
		else
			cout << "Stack underflow" << endl;
	}
	void setsize(int n)
	{
		size = n;
		arr = new T[n];
	}
	void display()
	{
		if (top == -1)
			cout << "empty stack" << endl;
		else
		{
			for (int i = 0; i < (top + 1); i++)
				cout << arr[i] << " ";
			cout << endl;
		}
	}
	bool IsEmpty()
	{
		return (top == -1);
	}
	bool IsFull()
	{
		return (top == (size - 1));
	}
	~stack()
	{}
};
int main()
{
	stack<int> s1;
	int x, op, val;
	cout << "Enter the size:" << endl;
	cin >> x;
	s1.setsize(x);
	cout << "Enter the operation:1)push 2)pop 3)peek 4)exit" << endl;
	while (1)
	{
		cin >> op;
		switch (op)
		{
		case 1:cout << "Enter the element to push:";
			cin >> val;
			s1.push(val);
			s1.display();
			break;
		case 2:val = s1.pop();
			cout << endl << "Popped element is:" << val << endl;
			s1.display();
			break;
		case 3:val = s1.peek();
			cout << "Top element is:" << val << endl;
			s1.display();
			break;
		case 4:
			cout << "Exiting..." << endl;
			exit(0);
		default:cout << "Enter a valid option..." << endl;
			break;
		}
	}
	return 0;
}