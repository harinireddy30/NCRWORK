#include<stdio.h>
#include<math.h>
char hex(int);
void main()
{
	int num, sum = 0, i, d = 0, rem, temp, x = 0, base, dec, j, q, q1;
	char a[20];
	printf("Enter the binary input\n");
	scanf_s("%d", &num);
	temp = num;
	while (num > 0)
	{
		rem = num % 10;
		num = num / 10;
		d++;
	}
	printf("The no of digits in the binary number is: %d\n", d);
	num = temp;
	base = 1;
	for (i = 0; i < d; i++)
	{
		rem = num % 10;
		sum = sum + rem * base;
		num = num / 10;
		base = base * 2;
		x++;
	}
	printf("The decimal equivalent is %d\n", sum);
	dec = sum;
	j = 0;
	printf_s("The hexadecimal equivalent is:\n");
	while (dec > 0)
	{
		q = dec % 16;
		q1 = hex(q);
		a[j] = q1;
		printf("%c", a[j]);
		j++;
		dec = dec / 16;
	}
	printf("\n");
	system("pause");
}
char hex(int q)
{
	switch (q)
	{
	case 0:
	{ return '0';
	break;
	}
	case 1:
	{ return '1';
	break;
	}
	case 2:
	{ return '2';
	break;
	}
	case 3:
	{ return '3';
	break;
	}
	case 4:
	{ return '4';
	break;
	}
	case 5:
	{ return '5';
	break;
	}
	case 6:
	{ return '6';
	break;
	}
	case 7:
	{ return '7';
	break;
	}
	case 8:
	{ return '8';
	break;
	}
	case 9:
	{ return '9';
	break;
	}
	case 10:
	{ return 'a';
	break;
	}
	case 11:
	{ return 'b';
	break;
	}
	case 12:
	{ return 'c';
	break;
	}
	case 13:
	{ return 'd';
	break;
	}
	case 14:
	{ return 'e';
	break;
	}
	case 15:
	{ return 'f';
	break;
	}
	}
}