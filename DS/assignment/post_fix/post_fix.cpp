#include<iostream>
using namespace std;
struct stack {
	int size;
	char *s;
	int top;
};
class __stack__
{
	stack s1;
public:
	__stack__()
	{
		s1.s = NULL;
		s1.top = -1;
		s1.size = 0;
	}
	void getsize(int n)
	{
		s1.size = n;
		s1.s = new char[n];
	}
	void push(int ele)
	{
		if (!IsFull())
			s1.s[++s1.top] = ele;
		else
			cout << "Overflow" << endl;
	}
	bool IsFull()
	{
		return(s1.top == (s1.size - 1));
	}
	char pop()
	{
		if (!Isempty())
			return(s1.s[s1.top--]);
		else
			cout << "Underflow";
	}
	bool Isempty()
	{
		return (s1.top == -1);
	}
	char peek()
	{
		return(s1.s[s1.top]);
	}
	void display()
	{
		for (int i = 0; i <= s1.top; i++)
			cout << s1.s[i] << endl;
	}
};
void main()
{
	__stack__ st;
	int i = 0;
	st.getsize(20);
	char a[20];
	cout << "Enter postfix string" << endl;
	cin >> a;
	cout << "post fix expression:" << a;
	while (a[i] != '\0')
	{
		if (a[i] >= 48 && a[i] <= 57)
		{
			st.push(a[i]);
		}
		else
		{
			if (a[i] == '+')
			{
				st.push(((int)st.pop()) + ((int)st.pop()));
			}

		}
	