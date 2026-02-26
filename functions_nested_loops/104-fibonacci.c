#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long f1 = 1, f2 = 2, i, head = 1000000000;
	unsigned long f1_h, f1_l, f2_h, f2_l, n_h, n_l;

	printf("%lu, %lu", f1, f2);
	for (i = 3; i <= 91; i++)
	{
		f2 = f1 + f2;
		f1 = f2 - f1;
		printf(", %lu", f2);
	}
	f1_h = f1 / head;
	f1_l = f1 % head;
	f2_h = f2 / head;
	f2_l = f2 % head;
	for (i = 92; i <= 98; i++)
	{
		n_h = f1_h + f2_h + (f1_l + f2_l) / head;
		n_l = (f1_l + f2_l) % head;
		printf(", %lu%09lu", n_h, n_l);
		f1_h = f2_h;
		f1_l = f2_l;
		f2_h = n_h;
		f2_l = n_l;
	}
	printf("\n");
	return (0);
}
