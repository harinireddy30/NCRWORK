/*STRING FUNCTIONS(STRING COMPARISON, STRING REVERSAL,STRING CONCATENATION, STRING COPYING) IMPLEMENTATION*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int strcomp(char *s1, char *s2);
void strcopy(char *s1, char *s2);
void reversal(char *s1, char *s2);
void strconc(char *s1, char *s2);
int main()
{
	printf("The four operations are:\n 1)String Comparison 2)String Reversal\n 3)String Concatenation 4)String Copying\n");
	char *p1, *p2;                       //pointers to two strings
	printf("Enter the operation:");
	int x;
	scanf("%d", &x);
	switch (x)
	{
	case 1:
	{
		int res, n1, n2;
		printf("Enter the sizes of string1 and string2:\n");
		scanf("%d %d", &n1, &n2);
		p1 = (char *)malloc(n1 * sizeof(char));
		p2 = (char *)malloc(n2 * sizeof(char));
		if (p1 == NULL || p2 == NULL)
			printf("Memory not allocated\n");
		printf("Enter the strings to compare:\n");
		scanf("%s", p1);
		scanf("%s", p2);
		res = strcomp(p1, p2);
		if (res == 0)
			printf("The strings are equal\n");
		else
			printf("The strings are not same\n");
		free(p1);
		free(p2);
		break;
	}
	case 2:
	{
		int n;
		printf("Enter the size of string s1 to reverse:\n");
		scanf("%d", &n);
		printf("Enter the string s1 to reverse:\n");
		p1 = (char *)malloc(n * sizeof(char));
		p2 = (char *)malloc(n * sizeof(char));
		if (p1 == NULL||p2==NULL)
			printf("Memory not alloacted\n");
		scanf("%s", p1);
		reversal(p1, p2);
		free(p1);
		free(p2);
		break;
	}
	case 3:
	{
		int n1, n2;
		printf("Enter the sizes of string1 and string2:\n");
		scanf("%d %d", &n1, &n2);
		p1 = (char *)malloc((n1+n2) * sizeof(char));
		p2 = (char *)malloc(n2 * sizeof(char));
		printf("Enter the two strings to concatenate:\n");
		scanf("%s", p1);
		scanf("%s", p2);
		strconc(p1, p2);
		free(p1);
		free(p2);
		break;
	}
	case 4:
	{
		int n1, n2;
		printf("Enter the size of string1 and string2:\n");
		scanf("%d %d", &n1, &n2);
		p1 = (char *)malloc(n1 * sizeof(char));
		p2 = (char *)malloc(n2 * sizeof(char));
		if (p1 == NULL || p2 == NULL)
			printf("Memory not allocated\n");
		printf("Enter the string s1 to copy to string s2\n");
		scanf("%s", p1);
		strcopy(p1, p2);
		free(p1);
		free(p2);
		break;
	}
	}
	system("pause");
	return 0;
}
int strcomp(char *s1, char *s2)
{
	int i = 0, j = 0, flag = 0;
	while (s1[i] == s2[j])
	{
		if (s1[i] == '\0')                
		{
			flag = 1;                         //set flag to 1 if the string characters are same until '\0'
			break;
		}
		i++;
		j++;
	}
	if (flag == 1)
		return 0;
	else
		return 1;
}
void strcopy(char *s1, char *s2)
{
	int i, j = 0;
	for (i = 0; i < strlen(s1); i++)
		s2[j++] = s1[i];                                   //copy contents into string2 till string1 reaches NULL character
	s2[j] = '\0';                                          //add NULL character at end of string2
	printf("The contents of string2 after copying are:\n");
	for (j = 0; j < strlen(s2); j++)          
		printf("%c", s2[j]);
	printf("\n");
}
void reversal(char *s1, char *s2)
{
	int i = 0, j = strlen(s1) - 1;                   //i-index to s1(original string),j-index to end of s2(destination string)
	while (s1[i] != '\0')
	{
		s2[j] = s1[i];
		i++;
		j--;
	}
	j = j + strlen(s1) + 1;                   //set j to actual position as it reaches 0 after the loop ends
	s2[j] = '\0';
	i = 0;
	while (s2[i] != '\0')
	{
		printf("%c", s2[i]);
		i++;
	}
	printf("\n");
}

void strconc(char *s1, char *s2)
{
	int i, j = 0;
	for (i = 0; s1[i] != '\0'; i++)                    //do nothing till the index reaches '\0'
		;
	for (j = 0; s1[j] != '\0'; j++)
		s1[i + j] = s2[j];                             //start concatenating once string1 is done
	s1[i + j] = '\0';
	printf("The concatenated string is:\n");
	printf("%s", s1);
	printf("\n");
}
