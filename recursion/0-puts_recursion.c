#include "main.h"

/**
 * _puts_recursion - prints a string, followed by a new line
 * @s: the string to be printed
 *
 * Description: This function uses recursion to iterate through
 * a string and print each character using _putchar.
 * Return: void
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);
	_puts_recursion(s + 1);
}
