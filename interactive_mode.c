#include "main.h"

/**
 * interactive_mode - A function that runs the shell as interactive
 *
 * Return: void
 */

void interactive_mode(void)
{
	char *Stdin, **argv;
	int check = -1;

	do{
		_write(prompt);
		Stdin = read_stdin();
		argv = tokenize_stdin(Stdin);
		check = execute(argv);
		
		free(Stdin);
		free(argv);

		if (check >= 0)
			exit(check);
	}
	while(check == -1);
}
