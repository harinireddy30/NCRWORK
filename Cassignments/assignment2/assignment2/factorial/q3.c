#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fact(int x);
void main()
{
	int num, result;
	printf("Enter the number:\n");
	scanf("%d", &num);
	result = fact(num);
	printf("The factorial is:%d", result);
	system("\npause");
}
int fact(int x)
{
	int res;
	if (x == 0)
		return 1;
	else
	{
		res = x * fact(x - 1);
		return res;
	}
}