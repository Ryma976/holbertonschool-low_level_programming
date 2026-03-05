#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer
 * @b: buffer to print
 * @size: size of buffer
 */
void print_buffer(char *b, int size)
{
	int offset, i, j;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	for (offset = 0; offset < size; offset += 10)
	{
		printf("%08x: ", offset);
		for (i = 0; i < 10; i++)
		{
			if ((i + offset) >= size)
				printf("  ");
			else
				printf("%02x", b[i + offset]);
			if (i % 2 != 0)
				printf(" ");
		}
		for (j = 0; j < 10; j++)
		{
			int pos = j + offset;

			if (pos >= size)
				break;
			if (b[pos] >= 32 && b[pos] <= 126)
				printf("%c", b[pos]);
			else
				printf(".");
		}
		printf("\n");
	}
}
