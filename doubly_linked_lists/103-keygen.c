#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a key for crackme5 based on a username.
 * @argc: The number of arguments.
 * @argv: The arguments vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	unsigned int i, sum;
	size_t len;
	char *lookup;
	char key[7];

	if (argc != 2)
		return (1);

	lookup = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU4m163oejukq9fIhPaWdZ87";
	len = strlen(argv[1]);
	sum = 0;

	for (i = 0; i < len; i++)
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
