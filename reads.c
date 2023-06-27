#include "main.h"

/**
 * read_strm - a function that reads a line from the stream
 * Return: a pointer to the line read from the stream
 */

char *read_strm(void)
{
	int i = 0, n = 1024;
	int input;

	char *Stdin = malloc(sizeof(char) * n);

	if (Stdin == NULL)
	{
		fprintf(stderr, "read_strm: malloc failed");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		input = getchar();
		if (input == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (input == '\n')
		{
			Stdin[i] = '\0';
			return (Stdin);
		}
		else
		{
			Stdin[i] = input;
		}
		i++;
		if (i >= n)
		{
			n += n;
			Stdin = realloc(Stdin, n);
			if (Stdin == NULL)
			{
				fprint(stderr, "read_strm: realloc failed");
				exit(EXIT_FAILURE);
			}
		}
	}
}
