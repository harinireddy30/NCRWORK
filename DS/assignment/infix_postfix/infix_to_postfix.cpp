#include<iostream>
using namespace std;
class stack {
	int top;
	char *str;
	int size;
public:
	stack()
	{
		top = -1;
		size = 0;
	}
	void set_size(int x)
	{
			size = x;
			str = new char[x];
	}
	bool overflow()
	{
		return (top == (size - 1));
	}
	bool underflow()
	{
		return (top == -1);
	}
	void push(char x)
	{
		if (overflow())
			cout << "Stack overflow" << endl;
		else
		{
			str[++top] = x;
		}
	}
	void pop()
	{
		if (underflow())
			cout << "Underflow" << endl;
		else
		{
			char x = str[top--];
			cout << x;
		}
	}
	char peek()
	{
		if (underflow())
			cout << "Empty stack" << endl;
		else
			return (str[top]);
	}
	int precedence(char ch)
	{
		if ((ch == '+') || (ch = '-'))
			return 2;
		else if ((ch == '*') || (ch == '/') || (ch == '%'))
			return 3;
		else if (ch == '(' || ch == '[' || ch == '{')
			return 1;
		else
			return -1;
	}
};
int main()
{
	int i = 0;
	stack s1;
	s1 = stack();
	int n;
	cout << "Enter the size of the stack" << endl;
	cin >> n;
	s1.set_size(n);
	cout << "Enter the expression" << endl;
	char ch[20];
	cin >> ch;
	while (ch[i] != '\0')
	{
		if (isalpha(ch[i]) || isdigit(ch[i]))
			cout << ch[i];
		else if (s1.underflow())
			s1.push(ch[i]);
		else if (ch[i] == '(' || ch[i] == '[' || ch[i] == '{')
			s1.push(ch[i]);
		else if (ch[i] == ')')
			{
				while (s1.peek() != '(')
					s1.pop();
				s1.pop();
			}
		else if (ch[i] == ']')
			{
				while (s1.peek() != '[')
					s1.pop();
				s1.pop();
			}
		 else if (ch[i] == '}')
			{
				while (s1.peek() != '{')
					s1.pop();
				s1.pop();
			}
		else if(s1.precedence(ch[i])>s1.precedence(s1.peek()))
			s1.push(ch[i]);
	  i++;
	}
	while (!s1.underflow())
		s1.pop();
	system("pause");
	return 0;
}