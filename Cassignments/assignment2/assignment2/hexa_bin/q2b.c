#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void main()
{
	int num, n, d = 0, rem, temp, a[20], i, j;
	printf("Enter the hexadecimal number\n");
	scanf_s("%x", &num);
	temp = num;
	num = temp;
	i = 0;
	while (num > 0)
	{
		rem = num % 2;
		a[i] = rem;
		num = num / 2;
		i++;
	}
	printf("The binary value is \n");
	for (j = (i - 1); j >= 0; j--)
		printf("%d", a[j]);
	system("pause");
}