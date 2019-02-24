#include<iostream>
using namespace std;
class stack {
	int s[20];
	int n, top;
public:
	stack();
	void push(int);
	int pop();
	void display();
};
stack::stack()
{
	top = -1;
	cout << "Enter the no of elements in the stack" << endl;
	cin >> n;
}
void stack::push(int ele)
{
	if (top == (n - 1))
		cout << "Stack overflow" << endl;
	else
	{
		s[++top] = ele;
	}
}
int stack::pop()
{
	int x = -9999;
	if (top == 0)
		cout << "Stack underflow" << endl;
	else
	{
		x = s[top--];
	}
	return x;
}
void stack::display()
{
	int i;
	if (top == -1)
		cout << "Empty stack" << endl;
	else
	{
		for (i = top; i >= 0; i--)
			cout << s[i] << " ";
	}
}
void main()
{
	int a, x, i;
	stack s1;
	int flag = 1;
	cout << "Enter the option:" << endl;
	cout << "1,push 2.pop 3.display" << endl;
	while (flag)
	{
		cin >> i;
		switch (i)
		{
		case 1:
		{
			cout << "Enter element to push:";
			cin >> a;
			s1.push(a);
			break;
		}
		case 2:
		{
			a = s1.pop();
			cout << "Popped element is:" << a << endl;
			break;
		}
		case 3:
		{
			s1.display();
			break;
		}
		default:cout << "Wrong option";

		}
	}
	cin >> x;
}