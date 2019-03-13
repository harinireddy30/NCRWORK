#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void itob(int num, int s[]);
void itoh(int num, int s[]);
int main()
{
	int num, s[20];
	printf("Enter the number:\n");
	scanf("%d", &num);
	itob(num, s);
	itoh(num, s);
	system("\n pause");
	return 0;
}
void itob(int num, int s[])
{
	int temp = num, s1[20];
	int i = 0;
	while (temp > 0)
	{
		s[i] = temp % 2;
		temp = temp / 2;
		i++;
	}
	s[i] = 0;
	int n = i;
	for (i = 0; i <= n; i++)
		s1[i] = s[n-i];
	printf("The binary representation is:\n");
	for (i = 0; i <= n; i++)
		printf("%d", s1[i]);
}
void itoh(int num, int s[])
{
	int temp = num, s1[20], i=0;
	while (temp > 0)
	{
		s[i] = temp % 16;
		temp = temp / 16;
		i++;
	}
	s[i] = 0;
	int n = i;
	for (i = 0; i <= n; i++)
		s1[i] = s[n - i];
	printf("\nThe hexadecimal equivalent is:\n");
	for (i = 0; i <= n; i++)
		printf("%x", s1[i]);
	printf("\n");
}