#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j;

	j = 0;
	/* نسخ الحروف من المصدر إلى الوجهة */
	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}

	/* تعبئة ما تبقى من n بالأصفار إذا كان المصدر قصيراً */
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}

	return (dest);
}
