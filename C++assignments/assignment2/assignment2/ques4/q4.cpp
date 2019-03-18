/*overloading of unary and binary operators of complex class*/

#include<iostream>
using namespace std;
class complex {
	int real;
	int img;
public:
	complex()
	{
		real = img = 0;                                            //default constructor
	}
	complex(int x, int y)                                          //parameterized constructor
	{
		real = x;
		img = y;
	}
	complex(const complex &x)                                      //copy constructor
	{
		real = x.real;
		img = x.img;
	}
	complex operator+(complex c)                                  //overloading of + operator
	{
		complex res;
		res.real = real + c.real;
		res.img = img + c.img;
		return(res);
	}
	complex operator-(complex c)                                 //overloading of - operator
	{
		complex res;
		res.real = real - c.real;
		res.img = img - c.img;
		return (res);
	}
	complex operator++(int x)                                   //overloading of post-inc operator
	{
		complex temp;
		temp.real = real++;
		temp.img = img++;
		return temp;
	}
	complex operator--()                                       //overloading of post-dec operator
	{
		complex temp;
		temp.real = --real;
		temp.img = --img;
		return (temp);
	}
	complex operator,(complex c)                               //overloading of comma operator
	{
		return (c);
	}
	complex *operator->()                                      //overloading of -> operator(returns pointer of the object through which it entered)
	{
		return(this);
	}
	friend ostream& operator<<(ostream &cout, complex c);
	~complex()                                                 //destructor
	{
		cout << "destructor called" << endl;
	}
};
ostream& operator<<(ostream &cout, complex c) {                 //overloading of output overloading operator
	if (c.img < 0)
		cout << c.real << "-" << "i" << c.img << endl;        //positive complex
	else
		cout << c.real << "i" << c.img << endl;               //negative complex
	return cout;
}
void main()
{
	int y;
	complex c4;
	complex c1();
	cout << c1;
	complex c2(2, 3);
	cout << c2;
	complex c3(c2);
	cout << c3;
	c4 = c3++;
	cout << c3;
	complex c5 = c3 - c2;
	cout << c5;
	c5 = c3 + c2;
	cout << c5;
	cin >> y;
}
