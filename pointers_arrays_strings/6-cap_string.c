#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: string to modify
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *s)
{
	int i, j;
	char sep[] = " \t\n,;.!?\"(){}";

	i = 0;
	while (s[i] != '\0')
	{
		/* تحويل الحرف الأول في السلسلة إذا كان صغيراً */
		if (i == 0 && (s[i] >= 'a' && s[i] <= 'z'))
			s[i] -= 32;

		j = 0;
		while (sep[j] != '\0')
		{
			/* إذا كان الحرف الحالي حرفاً صغيراً ويسبقه فاصل */
			if (s[i] == sep[j])
			{
				if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
				{
					s[i + 1] -= 32;
				}
			}
			j++;
		}
		i++;
	}

	return (s);
}
