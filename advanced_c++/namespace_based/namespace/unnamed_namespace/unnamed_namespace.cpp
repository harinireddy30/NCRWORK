#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
namespace {
	int operand1;
	int operand2;
	class addition {
		int sum;
	public:
		addition()
		{
			                 //default constructor
		}
		int add_result(int op1, int op2)
		{
			sum = op1 + op2;
			return sum;
		}
	};
}
int main()
{
	addition result_obj;
	printf("Enter the operands\n");
	scanf("%d %d", &operand1, &operand2);     //uses unnamed namespace if name isn't mentioned
	printf("The result is: %d", result_obj.add_result(operand1, operand2));    
	system("pause");
	return 0;
}