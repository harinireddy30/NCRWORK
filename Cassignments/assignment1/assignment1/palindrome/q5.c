#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include<math.h>

int powerof(int, int);

int main()

{
	int number, rem = 0, number_new=0,temp;
	printf("Enter the number to check:\n");
	scanf("%d", &number);
	temp = number;
	while (number != 0)
	{
		rem = number % 10;
		number_new= number_new*10 + rem;
		number = number / 10;
	}
	if (number_new == temp)
		printf("The number is a palindrome\n");
	else
		printf("The number is not a palindrome\n");
	system("pause");
	return 0;

}
