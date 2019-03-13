#include<stdio.h>
void main()
{
	int n, count = 0, i, rem, temp, a[8], x;
	printf("enter a number between 0 and 255\n");
	scanf_s("%d", &n);
	temp = n;
	for (i = 0; i < 8; i++)
	{
		rem = n % 2;
		a[7 - i] = rem;
		n = n / 2;
	}
	for (i = 0; i < 8; i++)
	{
		if (a[i] == 1)
			count++;
	}
	printf("The number of '1's in the number is %d\n", count);
	scanf_s("%d", &x);
}
