#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()

{
	int i, num, j, r, s, t, temp, a[100];

	i = 0;

	scanf("%d ", &num);

	while (num > 0)

	{
		a[i + 1] = num;

		i++;

		scanf("%d ", &num);

	}

	temp = a[1];

	for (j = 2; j <= i; j++)

	{
		if (a[j] > temp)

			temp = a[j];

	}

	r = temp;

	printf("the maximum number is %d ", r);

	for (j = 2; j <= i; j++)

	{
		if (a[j] < temp)

			temp = a[j];

	}

	s = temp;

	printf("the minimum value is %d ", s);

	t = (r + s) / 2;

	printf("the average number is %d ", t);
	system("pause");

	return 0;
}