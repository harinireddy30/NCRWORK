#include <stdio.h>

#include <string.h>

int main()

{
	char *temp;

	char *names[] = {
"doctor","engineer","dentist","teacher","dancer" };

	int i, j, a;

	printf("The names are:\n");

	for (i = 0; i < 5; i++)

		printf("%s\n", names[i]);

	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			a = strcmp(names[i], names[j]);

			if (a > 0)
			{
				temp = names[i];

				names[i] = names[j];

				names[j] = temp;

			}

		}

	}

	printf("The sorted names are:\n");

	for (i = 0; i < 5; i++)

		printf("%s\n", names[i]);

	return 0;

}