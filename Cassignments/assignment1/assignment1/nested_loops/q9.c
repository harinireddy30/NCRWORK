#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int row_no;
	int i;
	for (row_no = 1; row_no <= 5; row_no++)
	{
		for (i = 0; i < (5 - row_no); i++)
		{
			printf(" ");
		}
		for (i = row_no; i > 0; i--)
		{
			printf("%d", i);
		}
		i++;
		while (i <= row_no)
		{
			if (i == 1)
				i++;
			else
			{
				printf("%d", i);
				i++;
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}