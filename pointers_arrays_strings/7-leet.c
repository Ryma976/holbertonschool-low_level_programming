#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to be encoded
 *
 * Return: pointer to the modified string
 */
char *leet(char *s)
{
	int i, j;
	char s1[] = "aAeEoOtTlL";
	char s2[] = "4433007711";

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (j < 10)
		{
			if (s[i] == s1[j])
			{
				s[i] = s2[j];
			}
			j++;
		}
		i++;
	}

	return (s);
}
