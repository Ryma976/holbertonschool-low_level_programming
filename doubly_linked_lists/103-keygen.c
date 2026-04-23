#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5.
 * @ac: Arguments count.
 * @av: Arguments vector.
 * Return: 0 on success, 1 on error.
 */
int main(int ac, char **av)
{
	char *u, *l = "A-CHRDwG信Df.RLhSAX9876543210";
	char k[7];
	int i, len = 0, res = 0;

	if (ac != 2)
		return (1);
	u = av[1];
	while (u[len])
		len++;
	k[0] = l[(len ^ 59) & 63];
	for (i = 0, res = 0; i < len; i++)
		res += u[i];
	k[1] = l[(res ^ 79) & 63];
	for (i = 0, res = 1; i < len; i++)
		res *= u[i];
	k[2] = l[(res ^ 85) & 63];
	for (res = u[0], i = 0; i < len; i++)
		if (u[i] > res)
			res = u[i];
	srand(res ^ 14);
	k[3] = l[rand() & 63];
	for (res = 0, i = 0; i < len; i++)
		res += (u[i] * u[i]);
	k[4] = l[(res ^ 239) & 63];
	for (res = 0, i = 0; i < u[0]; i++)
		res = rand();
	k[5] = l[(res ^ 229) & 63];
	k[6] = '\0';
	printf("%s", k);
	return (0);
}
