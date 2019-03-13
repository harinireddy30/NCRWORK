#include<stdio.h>

#include<string.h>

int any(char s1[], char s2[]);

void main()

{
	int i = 0, j = 0, x, z;

	char s1[20];

	char s2[20];

	printf("Enter the strings\n");

	gets(s1);

	gets(s2);

	x = any(s1, s2);

	if (x == 0)

		printf("No matching characters\n");

	else

		printf("The index is %d", x);

	scanf_s("%d", &z);

}

int any(char s1[], char s2[])

{
	int x = 0;

	int i;
	int j;

	for (i = 0; i != '\0'; i++)

	{
		for (j = 0; j != '\0'; j++)

		{
			if (s1[i] == s2[j])

				x = i;

		}

	}

	return x;

}