#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<math.h>

int powerof(int, int);

int main()

{

	int num, digits, sum, rem, i, temp;

	digits = 0, sum = 0;

	printf("enter the number\n");

	scanf("%d", &num);

	temp = num;

	while (temp != 0)

	{
		digits = digits++;

		temp = temp / 10;

	}

	temp = num;

	for (i = 0; i < digits; i++)

	{
		rem = temp % 10;

		sum = sum + powerof(rem, digits);

		temp = temp / 10;

	}

	if (num == temp)

		printf("its an armstrong number\n");

	else

		printf("its not an armstrong number\n");
	system("pause");
	return 0;

}

int powerof(int a, int b)

{
	int p = 1, r;

	for (r = 1; r <= b; r++)

	{
		p = p * a;

	}

	return p;

}