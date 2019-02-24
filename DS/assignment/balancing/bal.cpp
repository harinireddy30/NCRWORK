#include<iostream>
using namespace std;
struct stack {
	int top;                           //top of the stack
	int n;                             //size of stack
	char *ch;                          //pointer pointing to stack
};
class bal{
	struct stack s1;                   //data member of type structure stack
public:
	bal()                              
	{
		s1.top = -1;
		s1.n = 0;
		s1.ch = NULL;
	}
	void set_data(int x)                   //set data to structure 
	{
		s1.n = x;
		s1.ch = new char[x];
	}
	bool empty()                           //check if stack is empty 
	{
		return (s1.top == -1);
	}
	bool full()                            //check if stack is full
	{
		return (s1.top == (s1.n - 1));
	}
	char peek()                        //return the value at top
	{
		if (!empty())
			return (s1.ch[s1.top]);
		else
			return -1;
	}
	void push(int ele)
	{
		if (!full())
			s1.ch[++s1.top] = ele;
		else
			cout << "Overflow" << endl;
	}
	char pop()
	{
		if (!empty())
			return (s1.ch[s1.top--]);
		else
			return -1;
	}
	void display()
	{
		if (!empty())
			for (int i = 0; i <= s1.top; i++)
				cout << s1.ch[i] << " ";
		else
			cout << "Stack is empty" << endl;
	}
	~bal()
	{
		delete s1.ch;
	}
};
void main()
{
	char *s;
	s = new char[10];
	int i, x;
	cout << "Enter the string" << endl;
	cin >> s;
	int flag = 0;
	bal s1;
	s1.set_data(strlen(s));
	for (int i = 0; i < strlen(s); i++)
	{
		switch (s[i])
		{
		     case '{':
		     case '[':
		     case '(':s1.push(s[i]);
			          break;
			 case ')':
			 case ']':
			 case '}':
			 {
				 if (!s1.empty())
				 {
					 if ((s[i] == ']'&&s1.peek() == '[') || (s[i] == '}'&&s1.peek() == '{') || (s[i] == ')'&&s1.peek() == '('))
						 s1.pop();
					 else
						 flag = 1;
				 }
				 else
					 flag = 1;
				 break;
			 }
		}
	}
	s1.display();
	cin >> x;
}