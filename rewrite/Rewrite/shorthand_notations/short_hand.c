#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int expand(char s1[], char s2[]);
int main()
{
	int size;
	char s1[20], s2[50];                                //string s1 for input expression and s2 for resultant expression
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
			if (initial <= final)                           //checks if leftside value of'-' is less than rightside value
			{
				while (initial != final)                    //copy until the final value is reached
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
				printf("Enter a valid sequence\n");             //exception-ask for a valid input
				break;
			}
		}
		else
		{
			s2[j++] = s1[i++];                                  //store the value if '-' is not encountered
		}
	}
	return (j-1);                                              //return the size of storing array
}