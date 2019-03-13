#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void main()
{
	int low, high, i,flag;
	printf("Enter the lower and higher limits:\n");
	scanf("%d %d", &low, &high);
	printf("The prime numbers are:\n");
	for (i = (low + 1); i < high; i++)
	{
		flag = 0;
		for (int x = 2; x <i; x++)
		{
			if (i % x == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			printf("%d ", i);
	}
	printf("\n");
	system("pause");
}