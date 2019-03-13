#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	char input[100], output[100], c;
	int i = 0, j = 0;
	printf("Enter the string\n");
	gets(input);
	for (i = 0; i < strlen(input); i++)
	{
		if (input[i] == ' ')
			output[j++] = '-';
		else
			output[j++] = input[i];
	}
	printf("\noutput string is\n");
	j = 0;
	while (output[j] != '\0')
	{
		printf("%c", output[j]);
		j++;
	}
}