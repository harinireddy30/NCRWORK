#include<iostream>
int addition(int a, int b);
int multiplication(int a, int b);
int subtraction(int a, int b);
float division(int a, int b);
using namespace std;
#define SIZE 50    //size of input expression
int result = 0;
class Stack                             
{
	struct _stack_                     //for character type data
	{
		int top;
		char *ele;
		int size;
	}stack;
public:
	Stack()
	{
		stack.ele = NULL;
		stack.size = 0;
	}
	Stack(int size)
	{
		stack.size = size;
		stack.ele = new char[size];
		stack.top = -1;
	}
	bool isEmpty()
	{
		if (stack.top == -1)
			return true;
		return false;
	}
	bool isFull()
	{
		if (stack.top == stack.size - 1)
		{
			return true;
		}
		return false;
	}
	void push(char x)
	{
		if (stack.top ==( stack.size - 1))
		{
			cout << "Stack Full";
			return;
		}
		else
		{
			stack.ele[++stack.top] = x;
		}
	}
	char pop()
	{
		int x = -99;
		if (stack.top == -1)
		{
			return x;
		}
		x = stack.ele[stack.top--];
		return x;
	}
	char Peek()
	{
		int x = -99;
		if (stack.top == -1)
		{
			return x;
		}
		else
		{
			x = stack.ele[stack.top];
			return x;
		}
	}
	void Display()
	{
		for (int i = 0; i <= stack.top; i++)
		{
			cout << stack.ele[i];
		}
	}
	~Stack()
	{
		delete (stack.ele);
	}
};
int Precedence(char x)             //to set precedence of each operator
{
	if (x == '*' || x == '/')
		return  3;
	else if (x == '+' || x == '-')
		return 2;
	else
		return 1;
}
class Stack_eval
{
	struct sta                    //for integer type elements
	{
		int top;
		int *ele;
		int size;
	}stack;
public:
	Stack_eval()
	{
	}
	Stack_eval(int size)
	{
		stack.size = size;
		stack.ele = new int[size];
		stack.top = -1;
	}
	bool isEmpty()
	{
		if (stack.top == -1)
			return true;
		return false;
	}
	bool isFull()
	{
		if (stack.top == (stack.size - 1))
		{
			return true;
		}
		return false;
	}
	void push(int x)
	{
		if (stack.top == stack.size - 1)
		{
			cout << "Stack Full";
			return;
		}
		else
		{
			stack.ele[++stack.top] = x;
		}
	}
	int pop()
	{
		int x = -99;
		if (stack.top == -1)
		{
			cout << "Stack Empty";
			return x;
		}
		else
		{
			x = stack.ele[stack.top--];
			return x;
		}
	}
	int Peek()
	{
		int x = -99;
		if (stack.top == -1)
		{
			cout << "Stack Empty";
			return x;
		}
		else
		{
			x = stack.ele[stack.top];
			return x;
		}
	}
	void Display()
	{
		for (int i = 0; i <= stack.top; i++)
		{
			cout << stack.ele[i] << endl;
		}
	}
	~Stack_eval()
	{
		delete (stack.ele);     //destructor
	}
};
int main()
{
	char input_string[SIZE]; 
	char result[SIZE];
	cout << "Enter the input expression to evaluate:";
	cin >> input_string;
	Stack s(20);                        
	char ch;
	int j = 0;
	for (int i = 0; i < strlen(input_string); i++)      //conversion of infix to postfix 
	{
		ch = input_string[i];
		if (isdigit(ch))
		{
			result[j++] = ch;                //push digits into result array
		}
		else if (isalpha(ch))
		{
			printf("Alphabets are not allowed.Please enter only digits as operands..\n");
			system("pause");
			return -1;
		}
		else if (ch == '$' || ch == '_' || ch == '#' || ch == '@' || ch == '!'||ch=='&'||ch=='~') 
		{
			printf("Invalid operator.Please enter valid operators '(' , '+' , '-' , '*' , '/' , ')' ");
			system("pause");
			return -1;
		}
		else if (ch == '(')
		{
			s.push(ch);
		}
		else if (ch == ')')       //pop elements till '(' is found
		{
			while (s.Peek() != '(')
			{
				result[j++] = s.pop();
			}
			s.pop();
		}
		else if (s.isEmpty())              //push the first operator if the stack is empty
		{
			s.push(ch);
		}
		else if (Precedence(ch) > Precedence(s.Peek()))    
		{
			s.push(ch);
		}
		else
		{
			while (Precedence(ch) <= Precedence(s.Peek()))      //pop elements till the precedence is less than the top element of stack
			{
				result[j++] = s.pop();
			}
			s.push(ch);
		}
	}
	while (!s.isEmpty())                    //pop remaining elements into result array till stack is empty
	{
		result[j++] = s.pop();
	}
	result[j] = '\0';
	Stack_eval s1(20);                           //to store the results during evaluation of postfix expression
	for (int i = 0; i < strlen(result); i++)                   //to evaluate the postfix expression
	{
		char ch;
		ch = result[i];
		if (isdigit(ch) && !s1.isFull())
		{
			s1.push(ch - '0');           //conversion of char type to int if its a digit
		}
		else
		{
			int a = s1.pop();                   //pop two elements if an operator is found
			int b = s1.pop();
			switch (ch)
			{
			case '+': s1.push(addition(b, a));
				break;
			case '-': s1.push(subtraction(b, a));
				break;
			case '*': s1.push(multiplication(b, a));
				break;
			case '/': s1.push(division(b, a));
				break;
			}
		}
	}
	cout << endl << "Result of the expression is:" << s1.pop() << endl;
	system("pause");
	return 0;
}