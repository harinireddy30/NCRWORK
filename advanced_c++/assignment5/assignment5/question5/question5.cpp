/*FUNCTION POINTERS*/

#include<iostream>
using namespace std;
int add(int op1, int op2)
{
	return (op1 + op2);
}
int mul(int op1, int op2)
{
	return (op1*op2);
}
int operate(int x, int y, int(*f)(int, int))
{
	return ((*f)(x, y));
}
class Operator{
public:
	Operator()
	{

	}
	virtual int operator()(int x,int y)
	{
		return (*this)(x, y);
	}
};
class addition:public Operator {
public:
	addition()
	{

	}
	virtual int operator()(int x, int y)             //overloading () operator for addition
	{
		return (x + y);
	}
};
class multiplication :public Operator {
public:
	multiplication()
	{

	}
	virtual int operator()(int x, int y)              //overloading () operator for multiplication
	{
		return (x * y);
	}
};
int operator_func(int x, int y, Operator *obj)
{
	return (*obj)(x, y);
}
int main()
{
	cout << "The result of addition is:" <<operate(5,29,add)<< endl;                //function pointers
	cout << "The result of multiplication is:" << operate(5, 29, mul) << endl;
	Operator *obj1 = new addition();
	Operator *obj2 = new multiplication();
	cout << "The result of addition is:" << operator_func(10, 20, obj1) << endl;         //pointers to classes
	cout << "The result of multiplication is:" << operator_func(10, 20, obj2) << endl;
	system("pause");
	return 0;
}
