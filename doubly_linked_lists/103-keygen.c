#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5
 * @argc: Number of arguments
 * @argv: Arguments vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	size_t i;
	unsigned int sum = 0;
	char *lookup = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU4m163oejukq9fIhPaWdZ87";
	char key[7];

	if (argc != 2)
		return (1);

	for (i = 0; i < strlen(argv[1]); i++)
		sum += argv[1][i];

	key[0] = lookup[(sum ^ 59) & 63];
	key[1] = lookup[(sum ^ 79) & 63];
	key[2] = lookup[(sum ^ 85) & 63];
	key[3] = lookup[(sum ^ 90) & 63];
	key[4] = lookup[(sum ^ 91) & 63];
	key[5] = lookup[(sum ^ 92) & 63];
	key[6] = '\0';

	printf("%s", key);

	return (0);
}
