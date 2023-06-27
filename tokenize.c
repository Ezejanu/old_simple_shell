#include "main.h"

/**
 * tokenize_stdin - A function that separates string into multiple strings
 * depending on DELIM
 *
 * @Stdin: The string to be split (From standard input)
 *
 * Return: A pointer to tokenized array
 */

char **tokenize_stdin(char *Stdin)
{
	int n = 64;
	int i = 0;
	char **all_tok = malloc(n * sizeof(char *));
	char *token;

	if (!all_tok)
	{
		fprint(stderr, "tokenize_stdin(): malloc() failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(Stdin, DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;

		all_tok[i] = token;
		i++;
		if (i >= n)
		{
			n += n;
			all_tok = realloc(all_tok, n * sizeof(char *));
			if (!all_tok)
			{
				fprintf(stderr, "tokenize_stdin: realloc() failed");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);

	}
	all_tok[i] = NULL;
	return (all_tok);
}
