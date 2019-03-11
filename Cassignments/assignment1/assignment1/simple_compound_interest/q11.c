#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include<math.h>

int main()

{
	int prin;

	int interest, term = 5, p, s, n, c;

	prin = 500000;

	printf("The principal amount is %d and term is %d years\n", prin, term);

	printf("Enter the rate of interest\n");

	scanf("%d", &interest);

	s = prin * (1 + (interest*term));

	printf("enter the choice:annual,semiannual,quarterly,monthly,daily\n");

	scanf("%d", &p);

	switch (p)

	{
	case 1:n = 1;

		break;

	case 2:n = 2;

		break;

	case 3:n = 4;

		break;

	case 4:n = 12;

		break;

	case 5:n = 365;

		break;

	}

	c = prin * pow((1 + (interest / n)), (n*term));

	printf("The simple interest is %d and compound interest is %d", s, c);

	return 0;

}