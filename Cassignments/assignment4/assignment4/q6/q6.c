#include<string.h>
void main()
{
	char str[20];
	int i, n = 0, temp, x;
	printf("Enter the string\n");
	scanf_s("%s", str);
	while (str[n] != '\0')
		n++;
	printf("The no of characters in the string is %d", n);
	for (i = 0; i < (n / 2); i++)
	{
		temp = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = temp;
	}
	printf("The reversed string is\n");
	for (i = 0; i < n; i++)
		printf("%c", str[i]);
	scanf_s("%d", &x);
}