#include<stdio.h>

#include<string.h>

void main()

{
	char str[50];

	int i = 0, x;

	printf("Enter the lowercase string\n:");

	scanf("%s", str);

	while (str[i] != '\0')

	{
		if (str[i] >= 'a'&&str[i] <= 'z')

			str[i] = str[i] - 32;

		else

			printf("Enter only lowercase letters\n");

		i++;

	}

	i = 0;

	printf("The modified string is:");

	while (str[i] != 0)

	{
		printf("%c", str[i]);

		i++;

	}

	scanf("%d", &x);

}