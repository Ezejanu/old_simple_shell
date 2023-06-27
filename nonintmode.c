#include "main.h"

/**
 * non_interactive_mode - a function for a command line interpreter
 */

void non_interactive_mode(void);
{
	char *Stdin, **argv;
	int status = -1;

	do {
		Stdin = read_strm();
		argv = tokenize_stdin(Stdin);
		status = execute(argv);

		free(Stdin);
		free(argv);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
