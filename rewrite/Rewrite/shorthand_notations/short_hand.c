#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int expand(char s1[], char s2[]);
int main()
{
	int size;
	char s1[20], s2[50];
	printf("Enter the string in s1:");
	scanf("%[^\n]s", s1);                              //accepts characters until it encounters space
	printf("The expression after expansion is:");
	int x=expand(s1, s2);
	for (size = 0; size <(x+1); size++)
		printf("%c", s2[size]);                       //printf the resultant array
	printf("\n");
	system("pause");
	return 0;
}
int expand(char s1[], char s2[])
{
	int i, j;
	i = 0; j = 0;
	while (i != strlen(s1)) 
	{
		if (s1[i] == '-')
		{
			int initial = s1[i - 1]+1;                      //prints from intial to final value when it encounters '-'
			int final = s1[i + 1];
			if (initial <= final)
			{
				while (initial != final)
				{
					s2[j] = initial;
					initial++;
					j++;
				}
				s2[j] = initial;
				i++;
			}
			else
			{
				printf("Enter a valid sequence\n");
				break;
			}
		}
		else
		{
			s2[j++] = s1[i++];
		}
	}
	return (j-1);
}