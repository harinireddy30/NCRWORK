#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void main()
{
	int sum, n, i, arr[20], sum1, j, x;
	printf("enter the number of inputs to be given ");
	scanf_s("%d", &n);
	printf("\n Enter the array\n");
	for (i = 0; i < n; i++)
		scanf_s("%d", &arr[i]);
	printf("enter the sum\n");
	scanf_s("%d", &sum);
	for (i = 0; i < n; i++)
	{
		j = i;
		sum1 = 0;
		while ((j < n) && (sum1 <= sum))
		{
			sum1 = sum1 + arr[j];
			if (sum1 == sum)
			{
				printf("the indexes are %d and %d ", i, j);
			}
			j++;
		}
	}
	scanf_s("%d", &x);
}