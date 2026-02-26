#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long f1 = 1, f2 = 2, next, i;
	unsigned long f1_h, f1_l, f2_h, f2_l, next_h, next_l;
	unsigned long head = 1000000000; /* مقسم لـ 9 خانات */

	/* طباعة أول 91 رقماً (التي لا تتجاوز سعة unsigned long) */
	printf("%lu, %lu", f1, f2);
	for (i = 3; i <= 91; i++)
	{
		next = f1 + f2;
		printf(", %lu", next);
		f1 = f2;
		f2 = next;
	}

	/* تقسيم الأرقام الحالية للبدء في الحساب المتقدم */
	f1_h = f1 / head;
	f1_l = f1 % head;
	f2_h = f2 / head;
	f2_l = f2 % head;

	for (i = 92; i <= 98; i++)
	{
		next_l = f1_l + f2_l;
		next_h = f1_h + f2_h + (next_l / head);
		next_l %= head;

		printf(", %lu%09lu", next_h, next_l);

		f1_h = f2_h;
		f1_l = f2_l;
		f2_h = next_h;
		f2_l = next_l;
	}
	printf("\n");
	return (0);
}
