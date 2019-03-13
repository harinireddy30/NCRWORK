#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
void main()
{
	int num, temp, rem, sum = 0;
	printf("Enter the binary number\n");
	scanf("%d", &num);
	temp = num;
	int i = 0;
	while (temp > 0)
	{
		rem = temp % 10;
		temp = temp / 10;
		sum = sum + rem * pow(2, i);
		i++;
	}
	printf("The decimal equivalent is:%d", sum);
	system("pause");
}