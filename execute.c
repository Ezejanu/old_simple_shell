#include "main.h"

/**
 * execute - Execute the command (Builtin or process)
 * @argv: String of commands and its flags
 *
 * Return: On success - 1
 *		else - 0
 */

int execute(char **argv)
{
	char *builtins_list[] = {
		"cd",
		"env",
		"exit"
		/* "help" */
	};
	int (*builtins[])(char **) = {
		&_cd,
		&_env,
		&endprog
		/* &_help */
	};
	unsigned long int i = 0;

	if (argv[0] == NULL)
		return (-1);

	for (; i < sizeof(builtins_list) / sizeof(char *); i++)
	{
		if (strcmp(argv[0], builtins_list[i]) == 0)
		{
			return ((*builtins[i])(argv));
		}
	}
	return (_process(argv));
}
