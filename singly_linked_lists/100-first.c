#include <stdio.h>

/**
 * first - prints a poem before the main function is executed.
 *
 * Description: uses the constructor attribute to run this function
 * before the program starts the main function.
 */
void __attribute__ ((constructor)) first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
