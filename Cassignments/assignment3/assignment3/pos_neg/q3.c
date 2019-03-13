#include<stdio.h>
void main()
{
	int n, i, a[50], b[50], j = 0, x, k;
	printf("enter the no of numbers to enter\n");
	scanf_s("%d", &n);
	printf("enter the numbers\n");
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	for (i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			b[j] = a[i];
			j++;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			b[j] = a[i];
			j++;
		}
	}
	for (k = 0; k < n; k++)
	{
		printf("%d ", b[k]);
	}
	scanf_s("%d", &x);
}
