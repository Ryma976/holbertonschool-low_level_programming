#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number as string
 * @n2: second number as string
 * @r: buffer to store result
 * @size_r: buffer size
 *
 * Return: pointer to the result, or 0 if it doesn't fit
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k = 0, sum = 0, carry = 0;
	int len1 = 0, len2 = 0, temp;


	while (n1[len1])
		len1++;
	while (n2[len2])
		len2++;
	if (len1 + 1 >= size_r || len2 + 1 >= size_r)
		return (0);

	i = len1 - 1;
	j = len2 - 1;
	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';

		if (k >= size_r - 1)
			return (0);

		r[k++] = (sum % 10) + '0';
		carry = sum / 10;
	}
	r[k] = '\0';
	for (temp = 0; temp < k / 2; temp++)
	{
		char tmp = r[temp];
		r[temp] = r[k - temp - 1];
		r[k - temp - 1] = tmp;
	}

	return (r);
}
