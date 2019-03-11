#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void rotate_right(int n, int b);
void main()
{
	int x, y;
	printf("enter the number and the no. of rotations\n");
	scanf("%d,%d", &x, &y);
	rotate_right(x, y);
}
void rotate_right(int n, int b)
{
	int d = 0, i, j, temp, r[20], a[20], rem;
	temp = n;
	while (temp > 0)
	{
		d++;
		temp = temp / 10;
	}
	for (i = 0; i < d; i++)
	{
		rem = n % 10;
		a[d - i - 1] = rem;
		n = n / 10;
	}
	for (i = 0; i < b; i++)
	{
		r[i] = a[d - b + i];
	}
	for (j = 0; j < (d - b); j++)
	{
		r[i] = a[j];
		i++;
	}
	printf("the shifted number is\n");
	for (i = 0; i < d; i++)
		printf("%d", r[i]);
}