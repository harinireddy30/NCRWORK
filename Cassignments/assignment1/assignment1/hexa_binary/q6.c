#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include<math.h>

int main()

{
	int num, rem, p, i;

	int a[5];

	rem = 0;

	printf("enter a number between 0 and 32\n");

	scanf("%d", &num);

	if (num > 0 && num < 32)

	{
		p = 4; a[0] = 1;

		while (p > 0)

		{
			rem = num % 2;

			num = num / 2;

			a[p] = rem;

			p--;

		}

		printf("the binary equivalent of %d is\t", num);

		for (i = 0; i < 5; i++)

		{
			printf("%d", a[i]);

		}

		printf("\n");

	}

	else

		printf("the number doesnt lie between 1 and 32");
	system("pause");

	return 0;

}