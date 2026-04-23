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
	char *user;
	char *lookup = "A-CHRDwG信Df.RLhSAX9876543210";
	char key[7];
	int len, i, res;

	if (argc != 2)
		return (1);

	user = argv[1];
	len = strlen(user);

	key[0] = lookup[(len ^ 59) & 63];
	for (i = 0, res = 0; i < len; i++)
		res += user[i];
	key[1] = lookup[(res ^ 79) & 63];
	for (i = 0, res = 1; i < len; i++)
		res *= user[i];
	key[2] = lookup[(res ^ 85) & 63];
	for (i = 0, res = user[0]; i < len; i++)
		if (res < user[i])
			res = user[i];
	srand(res ^ 14);
	key[3] = lookup[rand() & 63];
	for (i = 0, res = 0; i < len; i++)
		res += (user[i] * user[i]);
	key[4] = lookup[(res ^ 239) & 63];
	for (i = 0, res = 0; i < user[0]; i++)
		res = rand();
	key[5] = lookup[(res ^ 229) & 63];
	key[6] = '\0';
	printf("%s", key);
	return (0);
}
