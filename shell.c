#include "main.h"


/* Global variable to indicate if SIGINT was received */
volatile sig_atomic_t interrupted = 0;

/* Signal handler for SIGINT */
void handle_sigint(int signum)
{
    (void) signum;
	interrupted = 1;

}


int main(int argc, char *argv[], char *env[])
{
	char *shellprompt = "shell $: ";
	char *command = NULL, *commtoken = NULL;
	char *tmp = NULL, *argtoken = NULL;
	size_t n = 0; int i = 1;
	int gline = 0;
	(void) argc;
	(void) argv;
	(void) env;

	    signal(SIGINT, handle_sigint);


	_write(shellprompt);
	while (!interrupted)
	{
		gline = getline(&command, &n, stdin);
		if (gline  == -1)
		{
			free(command);
			return (-1);
		}
		
		if (check_command(command) == 2)
			continue;

		commtoken = strtok(command, "\n");
		if (check_command(commtoken) == 3)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		if(_env(commtoken))
			_printenv();
		tmp = strtok(commtoken, " ");
		argtoken = strtok(NULL, " ");

		if (argtoken != NULL)
		{
			do {
				argv[i++] = argtoken;
			} while
			((argtoken = strtok(NULL, " ")));
		}
		argv[i] ='\0';
		
			
		if (findpath(tmp, argv, env) != NULL)
		{
			argv[0] = tmp;
			_fork(argv, env);
		empty(argv);

		free(argv[0]);
		}
		i = 1;
		_write(shellprompt);

	}
	free(command);
return(0);
}
