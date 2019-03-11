#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()

{
	int val = 0xCAFE;

	int x = 0x000F, y;

	int choice;

	printf("Enter ur choice\n");

	scanf("%d", &choice);

	switch (choice)

	{
	case 0:

	{
		y = val & x;

		if (y == 0x000F)

			printf("The last four bits are ON\n");

		break;

	}

	case 1:

	{
		int x1 = 0x00FF;

		int x2 = 0xFF00;

		int y1 = val & x1;

		y1 = y1 << 8;

		int y2 = val & x2;

		y2 = y2 >> 8;

		int res = y1 | y2;

		printf("The reversed bytes represent %x", res);

		break;

	}

	case 2:

	{
		int x3 = 0xFFF0;

		int x4 = 0x000F;

		int y3 = val & x3;

		int y4 = val & x4;

		y3 = y3 >> 4;

		y4 = y4 << 12;

		int y5 = y3 | y4;

		printf("the result of rotating by one byte is %x", y5);

		break;

	}

	}
	system("pause");
	return 0;

}