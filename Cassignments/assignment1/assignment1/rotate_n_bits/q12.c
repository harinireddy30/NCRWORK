#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
void main()
{
	int num, temp, rem;
	int n=0, b;
	printf("Enter the number and the no of bits to rotate:\n");
	scanf("%d %d", &num,&b);
	temp = num;
	while (temp > 0)
	{
		temp = temp / 10;
		n++;
	}
	temp = num;
	while (b > 0)
	{
		rem = temp % 10;
		temp = temp / 10;
		temp= temp + (rem*pow(10, (n - 1)));
		b--;
	}
	printf("The new number after rotating is %d\n", temp);
	system("pause");
}