#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char string1[50];
	printf("Enter the string1:\n");
	scanf("%[^\n]s", string1);
	int i;
	int count_digits=0, count_alpha=0, count_tabs=0, count_blanks = 0;
	for(i=0;i<strlen(string1);i++)
	{
		if (string1[i]>='0'&&string1[i]<='9')
			count_digits++;
		else if ((string1[i]>='a'&&string1[i]<='z')||(string1[i]>='A'&&string1[i]<='Z'))
			count_alpha++;
		else if (string1[i] == '\t')
			count_tabs++;
		else if (string1[i] == ' ')
			count_blanks++;
		else if (string1[i] == '\n')
			break;
	}
	printf("The no of digits=%d,no of alphabets =%d,no of tabs=%d,no of blanks=%d\n", count_digits, count_alpha, count_tabs, count_blanks);
	system("pause");
	return 0;
}