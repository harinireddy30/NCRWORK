#include<iostream>
using namespace std;
class stack {
	int *arr;
	int size;
	int top;
public:
	stack()
	{
		arr = NULL;
		size = 0;
		top = -1;
	}
	stack(int *p, int size)
	{
		arr = new int[size];
		top = -1;
	}
	void push(int ele)
	{
		if (top == (size - 1))
			cout << "Stack overflow" << endl;
		else
		{
			arr[++top] = ele;
		}
	}
	int pop()
	{
		int x;
		if (top == -1)
			cout << "Stack underflow" << endl;
		else
		{
			x = arr[top--];
		}
	}
	operator int() {
		return (top + 1);
	}
};
int main()
{
	cout << "Pushing 10 elements.." << endl;
	int *ptr_stack, size = 20;
	stack stack_obj(ptr_stack, size);
	int i;
	for (i = 0; i < 10; i++)
		stack_obj.push(5);
	system("pause");
	return 0;
}