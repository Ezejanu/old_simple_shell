#include "main.h"

/**
 * _write - A function to print a string to the std out.
 * @str: string to be printed
 *
 * Return: void
 */

void _write(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		write(1, &str[i], 1);
}
