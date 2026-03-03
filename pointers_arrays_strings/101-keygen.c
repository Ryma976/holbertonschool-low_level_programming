#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords for the program 101-crackme.
 *
 * Return: Always 0.
 */
int main(void)
{
	int sum = 0;
	char c;

	srand(time(NULL));

	while (sum < (2772 - 127))
	{
		c = rand() % 127;
		if (c > 32) /* نختار حروفاً قابلة للطباعة فقط */
		{
			putchar(c);
			sum += c;
		}
	}

	/* إضافة الحرف الأخير المتمم للمجموع 2772 */
	putchar(2772 - sum);

	return (0);
}
