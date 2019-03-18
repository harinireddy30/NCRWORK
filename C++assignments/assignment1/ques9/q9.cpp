#include<iostream>
using namespace std;
class nums {
	int num1;
	int num2;
public:
	nums()                                           //default constructor
	{
		num1 = num2 = 0;
	}
	nums(int x, int y)                                ///parameterized constructor
	{
		num1 = x;
		num2 = y;
	}
	void display()
	{
		cout << "num1=" << num1 << "num2=" << num2 << endl;
	}
	void swap_value(nums a)                                     //member function to swap numbers by value
	{
		num1 = a.num2;
		num2 = a.num1;
	}
	void swap_ref(nums &b)                                     //member function to swap numbers by reference
	{
		num1 = b.num2;
		num2 = b.num1;
	}
};
void main()
{
	int x, y;
	nums c, d;
	c = nums();                                                //object c initialized with default constructor
	c.display();
	c = nums(2, 3);                                            //object d initialized with parameterized constructor
	c.display();
	cout << "enter the choice:swap_value(1) or swap_ref(2)" << endl;
	cin >> x;
	switch (x)
	{
	case 1:
	{d.swap_value(c);                                         //swapped numbers(by value)stored in object d
	d.display();
	break;
	}
	case 2:
	{d.swap_ref(c);                                           //swapped numbers(by reference)stored in object d
	d.display();
	break;
	}
	}
	cin >> y;
}