#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	/* نصل لنهاية الكلمة الأولى */
	while (dest[i] != '\0')
	{
		i++;
	}

	j = 0;
	/* ننسخ من src بشرطين: لم نصل لنهاية src ولم نتجاوز n */
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* نضع علامة النهاية دائماً */
	dest[i] = '\0';

	return (dest);
}
