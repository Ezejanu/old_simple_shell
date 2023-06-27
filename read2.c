#include "main.h"

/**
 * read_stdin - A function that gets the line
 * from the standard input (stdin)
 *
 * Return: A pointer to the string containing standard input
 */

char *read_stdin(void)
{
	char *Stdin = NULL;
	size_t n = 0;
	int gline = 0;

	gline = getline(&Stdin, &n, stdin);
	if (gline == -1)
	{
		if (feof(stdin))
		{
			free(Stdin);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(Stdin);
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}

	return (Stdin);
}
