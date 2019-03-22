/*TO DEMONSTRATE THE USE OF CONVERSION FUNCTIONS..*/

#include<iostream>
using namespace std;
class power_function {
	double base;
	int exponent;
	double result;
public:
    power_function(double b, double exp)
	{
		base = b;
		exponent = exp;
		result = 1;
		for (int i = 1; i <= exponent; i++)
			result = result * base;
	}
	operator double() {
		return result;
	}
};
int main()
{
	double b;
	int exp;
	cout << "Enter the values of base and exponent:" << endl;
	cin >> b;
	if (!cin)
	{
		cout << "Enter only digits.." << endl;
		system("pause");
		return -1;
	}
	cin >> exp;
	if (!cin)
	{
		cout << "Enter only integers.." << endl; 
		system("pause");
		return -1;
	}
	power_function obj1(1.1,2);
	double res;
	res = obj1+2;
	cout << "The result of the expression is:" << endl;
	cout << res << endl;
	system("pause");
	return 0;
}