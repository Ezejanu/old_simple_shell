#include "main.h"

/**
 * interactive_mode - A function that runs the shell as interactive
 *
 * Return: void
 */

void interactive_mode(void)
{
	char *Stdin, **argv;
	int status = -1;
	char *prompt = "theprompt$: ";

	do {
		_write(prompt);
		Stdin = read_stdin();
		argv = tokenize_stdin(Stdin);
		status = execute(argv);

		free(Stdin);
		free(argv);

		if (status >= 0)
			exit(status);
	} while
		(status == -1);
}
