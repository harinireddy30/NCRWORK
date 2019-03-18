/*use of inline functions*/
#include<iostream>
using namespace std;
inline int add(int x, int y)
{
	return(x + y);
}
inline int sub(int x, int y)
{
	return(x - y);
}
inline int divis(int x, int y)
{
	return(x / y);
}
inline int mod(int x, int y)
{
	return(x % y);
}
inline int mul(int x, int y)
{
	return(x * y);
}
class nums {
	int num1;
	int num2;
public:
	nums(int a, int b)
	{
		num1 = a;
		num2 = b;
	}
	void display()
	{
		cout << "The numbers are" << num1 << num2;
	}
};
void main()
{
	int x, a, b;
	cin >> a >> b;
	cout << "The sum is:" << add(a, b) << endl;
	cout << "The difference is:" << sub(a, b) << endl;
	cout << "The quotient is:" << divis(a, b) << endl;
	cout << "The remainder is:" << mod(a, b) << endl;
	cout << "The product is:" << mul(a, b) << endl;
	cin >> x;
}