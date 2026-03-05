#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer for result
 * @size_r: buffer size
 * Return: address of r or 0
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k = 0, sum = 0, carry = 0;
	int len1 = 0, len2 = 0, t;
	char tmp;
    /* سطر فارغ هنا ضروروي جداً بعد التعريفات */
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
	for (t = 0; t < k / 2; t++)
	{
		tmp = r[t];
		r[t] = r[k - t - 1];
		r[k - t - 1] = tmp;
	}
	return (r);
}
