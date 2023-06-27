#include "main.h"

/**
 * _process - A function that creates a new process
 * @argv: An array of strings containing commands and their flags
 *
 * Return: Success - 1
 *		else - 0
 */

int _process(char **argv)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
			perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error");
	}

	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}
