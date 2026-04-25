#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5
 * @ac: argument count
 * @av: argument vector (av[1] is the username)
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	unsigned int i, sum;
	char *username;
	char key[7];
	char *lookup = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU4m163oejukq9fIhPaWdZ87";

	if (ac != 2)
		return (1);

	username = av[1];
	sum = 0;

	for (i = 0; i < strlen(username); i++)
		sum += username[i];
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
