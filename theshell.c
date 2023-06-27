#include "main.h"

/**
 * main - a function that initiates the shell by checking
 * if it is called in interactive or non-interactive mode
 * Return: Always (0) on success
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 0)
	{
		non_interactive_mode();
	}
	else if (isatty(STDIN_FILENO) == 1)
	{
		interactive_mode();
	}

	return (0);
}
