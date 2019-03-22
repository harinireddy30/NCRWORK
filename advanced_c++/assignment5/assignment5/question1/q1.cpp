#include<iostream>
#include "namespace1.cpp"
#include "namespace2.cpp"
using namespace std;
using namespace namespace1;
using namespace namespace2;
int main()
{
	int operand1, operand2;
	int result;
	cout << "Enter the operands:" << endl;
	cin >> operand1 >> operand2;
	if (!cin)                                           //if the input values are not numbers,exit
	{
		cout << "Enter only numbers.." << endl;
		system("pause");
		return -1;
	}
	method1 obj1;                                             //method1 for normal addition and subtraction
	result=obj1.addition(operand1, operand2);
	cout << "Result of addition using namespace1 is:" <<result<< endl;
	result=obj1.subtraction(operand1, operand2);
	cout << "Result of subtraction using namespace2 is:" <<result<< endl;
	method2 obj2;                                            //method2 to perform addition and subtraction after modulus
	result = obj2.addition_after_mod(operand1, operand2);
	cout << "Result after addition using namespace2 is:" <<result<< endl;
	result = obj2.subtraction_after_mod(operand1, operand2);
	cout << "Result after subtraction using namespace2 is:" << result << endl;
	system("pause");
	return 0;
}