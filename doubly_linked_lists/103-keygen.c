#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5
 * @argc: argc
 * @argv: argv
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *u;
	char *l = "A-CHRDwG信Df.RLhSAX9876543210";
	char k[7];
	int len, i, r;

	if (argc != 2)
		return (1);
	u = argv[1];
	len = strlen(u);
	k[0] = l[(len ^ 59) & 63];
	for (i = 0, r = 0; i < len; i++)
		r += u[i];
	k[1] = l[(r ^ 79) & 63];
	for (i = 0, r = 1; i < len; i++)
		r *= u[i];
	k[2] = l[(r ^ 85) & 63];
	for (i = 0, r = u[0]; i < len; i++)
		if (r < u[i])
			r = u[i];
	srand(r ^ 14);
	k[3] = l[rand() & 63];
	for (i = 0, r = 0; i < len; i++)
		r += (u[i] * u[i]);
	k[4] = l[(r ^ 239) & 63];
	for (i = 0, r = 0; i < u[0]; i++)
		r = rand();
	k[5] = l[(r ^ 229) & 63];
	k[6] = '\0';
	printf("%s", k);
	return (0);
}
