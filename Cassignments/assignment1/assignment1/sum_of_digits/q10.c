#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include<math.h>

int main()

{
	int sum = 0, num, rem;

	printf("enter the number ");

	scanf("%d", &num);

	while (num > 0)

	{
		rem = num % 10;

		num = num / 10;

		sum = sum + rem;

	}

	printf("the sum of digits is %d", sum);
	system("pause");

	return 0;

}