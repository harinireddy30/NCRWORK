#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int num, rem, a[20], arr[20],n=0,b,p,temp;
	printf("Enter the number,p and b\n");
	scanf("%d %d %d", &num, &p, &b);
	temp = num;
	while (temp> 0)
	{
		temp = temp / 10;
		n++;
	}
	temp = num;
	if (b > (n - p))
	{
		printf("Enter valid values of p and b\n");
		return 0;
	}
	else
	{
		int i = (n-1);
		while (i >= 0)
		{
			rem = temp % 10;
			a[i] = rem;
			temp = temp / 10;
			i--;
		}
		int k = 0;
		for (i = p; i < (p + b); i++)
		{
			arr[k+b-1] = a[i];
			k--;
		}
		k = 0;
		for (i = p; i < (p + b); i++)
		{
			a[i] = arr[k];
			k++;
		}
		for (i = 0; i < n; i++)
			printf("%d", a[i]);
	}
	system("\n pause");
	return 0;
}