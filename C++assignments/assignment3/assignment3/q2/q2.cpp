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
	/*int size_of_stack()
	{
		return (top + 1);
	}*/
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
	~stack()
	{}
};
int main()
{
	stack<int> a;
	a = stack() < int > ;
	int x;
	//cout << "size of the stack till now is " << t.size() << endl;
	//int ans=(t.pop()|-1);
	a.push(0);
	a.push(2);
	x=a.pop();
	cout << "popped element is:" << x << endl;
	//cout << "size of the stack till now is " << t.size() << endl;
	//int temp = t.pop();
	//cout << "the top of the stack element is " << temp << endl;
	// to stop console from closing
	a.display();
	system("pause");
	return 0;
}