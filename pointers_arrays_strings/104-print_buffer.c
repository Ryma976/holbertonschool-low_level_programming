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
		/* 1. طباعة العنوان (Position) مكون من 8 خانات */
		printf("%08x: ", offset);

		/* 2. طباعة المحتوى الست عشري (Hex) كل بايتين معاً */
		for (i = 0; i < 10; i++)
		{
			if ((i + offset) >= size)
				printf("  ");
			else
				printf("%02x", b[i + offset]);

			if (i % 2 != 0)
				printf(" ");
		}

		/* 3. طباعة النص القابل للقراءة (Printable characters) */
		for (j = 0; j < 10; j++)
		{
			if ((j + offset) >= size)
				break;

			if (b[j + offset] >= 32 && b[j + offset] <= 126)
				printf("%c", b[j + offset]);
			else
				printf(".");
		}
		printf("\n");
	}
}
