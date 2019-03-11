#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void main()
{
	int basic, hra, da, gross;
	printf("Enter the basic pay of an employee\n");
	scanf("%d", &basic);
	if (0 < basic < 4001)
	{
		hra = 0.1*basic;
		da = 0.5*basic;
		gross = basic + hra + da;
	}
	else if (4000 < basic < 8001)
	{
		hra = 0.2*basic;
		da = 0.6*basic;
		gross = basic + hra + da;
	}
	else if (8000 < basic < 12001)
	{
		hra = 0.25*basic;
		da = 0.7*basic;
		gross = basic + hra + da;
	}
	else if (basic > 12000)
	{
		hra = 0.3*basic;
		da = 0.8*basic;
		gross = basic + hra + da;
	}
	else
		printf("enter a positive number\n");
	printf("the gross salary is %d\n", gross);
	system("pause");
}