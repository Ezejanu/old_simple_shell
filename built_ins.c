#include "main.h"

/**
 * endprog - a function to terminate the process and exit the shell
 * @argv: a string containing commands to be exited from
 * Return: 0 to end the process and exit the terminal
 */

int endprog(char **argv)
{
	if (argv[1])
		return (atoi(argv[1]));

	else
		return (0);
}


/**
 * _env - a function that prints the environment variables
 * @argv: a string containing commands/ arguments
 * Return: (-1) on success, (0) if fail.
 */

int _env(char **argv)
{
	int i;

	(void)argv;

	i = 0;
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}


/**
 * _cd - a function to change the working directory
 * @argv: destination directory to be changed to
 * Return: (-1) on success, (0) for failure
 */

int _cd(char **argv)
{
	if (argv[1] == NULL)
	{
		fprintf(stderr, "cd: invalid argument");
	}
	else
	{
		if (chdir(argv[1]) != 0)
			perror("Error");
	}
	return (-1);
}

/**
 * _help - a function to display help
 * @argv: string containing arguments
 * Return: (-1) for success, (0) if not success
 */


int _help(char **argv)
{
	(void) argv;

	return (-1);
}
