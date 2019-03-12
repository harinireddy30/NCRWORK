#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int num;
	scanf("%d", &num);
	int p, b, n=0, temp;
	temp = num;
	while (temp > 0)
	{
		temp = temp / 10;
		n++;
	}
	temp = num;
	int arr[20];
	printf("The no of bits is %d\n", n);
	printf("Enter the values of p and b:\n");
	scanf("%d %d", &p, &b);
	if (b > (n - p))
	{
		printf("\nEnter valid inputs p and b\n");
		return 0;
	}
	else
	{
		for (int i = 0; i <= p; i++)
		{
			
			arr[i] =
		}
	}
	return 0;
}