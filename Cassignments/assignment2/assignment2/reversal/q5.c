#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()

{
	int num, rev = 0, rem;

	printf("enter the number\n");

	scanf("%d", &num);

	while (num > 0)

	{
		rem = num % 10;

		rev = rev * 10 + rem;

		num = num / 10;

	}

	printf("the reversed number is %d \n", rev);
	system("pause");
	return 0;

}