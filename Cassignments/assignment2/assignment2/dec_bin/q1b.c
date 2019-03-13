#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
void main()
{
	int num, temp, arr[20], rev_arr[20];
	printf("Enter the decimal number:\n");
	scanf("%d", &num);
	temp = num;
	int i = 0;
	while (temp > 0)
	{
		arr[i] = temp % 2;
		temp = temp / 2;
		i++;
	}
	int n = i;
	arr[i] = 0;
	for (i = 0; i <= n; i++)
	{
		rev_arr[i] = arr[n - i];
		printf("%d", rev_arr[i]);
	}
	printf("\n");
	system("pause");
}