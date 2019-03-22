/*SHORTHAND NOTATION*/
/*STRING EXPANSION*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int expand(char s1[], char s2[]);
int main()
{
	int size, n;
	char s1[20], s2[20];                                //string s1 for input expression and s2 for resultant expression
	printf("\n Enter the string in s1:");
	scanf("%[^\n]s", s1);                              
	int x=expand(s1, s2);
	if (x != 0)
	{
		for (size = 0; size < (x + 1); size++)
			printf("%c", s2[size]);                       //print the resultant array
		printf("\n");
	}
	system("pause");
	return 0;
}
int expand(char s1[], char s2[])
{
	int i, j;
	i = 0; j = 0;
	while (i != strlen(s1))                                  //read characters till null character is encountered      
	{
		if (s1[i] == '-')
		{
			if (i==0)                                 //sequence starting with '-'
			{
				printf("Sequence can't start with '-' \n");
				return 0;
			}
			char initial = s1[i - 1]+1;                      //prints from intial to final value when it encounters '-'
			char final = s1[i + 1];
			if (final!='-'&&initial <= final)          //checks if the character after '-' is '-' and if leftside value of'-' is less than rightside value
			{
				while (initial != final)                    //copy until the final value is reached
				{
					s2[j] = initial;
					initial++;
					j++;
				}
				s2[j] = initial;                          //to copy the final value
				i++;
			}
			else
			{
				printf("Enter a valid sequence\n");             //exception-ask for a valid input
				return 0;
				break;
			}
		}
		else
		{
			s2[j++] = s1[i++];                                  //store the value if '-' is not encountered
		}
	}
	printf("The expression after evaluation is:\n");
	return (j-1);                                              //return the size of storing array
}