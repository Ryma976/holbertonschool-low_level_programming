#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0.
 */
int main(void)
{
	int count;
	long int f1 = 1, f2 = 2, next;

	printf("%ld, %ld", f1, f2);

	for (count = 3; count <= 50; count++)
	{
		next = f1 + f2;
		printf(", %ld", next);
		f1 = f2;
		f2 = next;
	}

	printf("\n");

	return (0);
}
