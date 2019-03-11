#include<iostream>
using namespace std;
class stack_parameters {
	char *stack;                       //pointer to the stack
	int top;                           //top of the stack
public:
	void set(int x)
	{
		stack = new char[x];      //allocating memory to the stack
		top = -1;
	}

	void push(char ele)
	{
		stack[++top] = ele;
	}
	void pop()
	{
		top--;
	}
	char peek()
	{
		return stack[top];                 //returns top element os the stack without popping
	}
	int isempty()
	{
		return(top == -1);                 //returns 1 if stack is empty
	}
};
int main()
{
	stack_parameters s1;
	s1.set(20);                              //size of stack
	char s[50];                             //string declaration
	int i, flag = 0;
	cout << "enter expression for checking balanced paranthesis" << endl;
	cin >> s;
	for (i = 0; i < strlen(s); i++)               //checks each element of the string
	{
		switch (s[i])
		{
		case'[':
		case'{':
		case '(':
		 {
			s1.push(s[i]);                       //'(' or '[' or'{' =>push on to the stack
			break;
		 }
		case'}':
		case ']':
		case ')':
		 {
			if (!s1.isempty())                   //')' or']' or'}' =>check with the top element of the stack;if equal=>pop
			{
				if ((s[i] == '}'&&s1.peek() == '{') || (s[i] == ']'&&s1.peek() == '[') || (s[i] = ')'&&s1.peek() == '('))
				{
					s1.pop();
					break;
				}
			}
			else
			{
				flag = 1;                        //set flag to 1  if characters are not equal
				break;
			}
		 }
		}		if (flag == 1)
			break;
	}
	if (s1.isempty() && flag == 0)
		cout << "Balanced" << endl;
	else
		cout << "Unbalanced" << endl;
	system("pause");
	return 0;
}