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
	size_t n = 0;
	(void) argc;
	(void) argv;
	(void) env;

	    signal(SIGINT, handle_sigint);


	_write(shellprompt);
	while (!interrupted)
	{
		if (getline(&command, &n, stdin) == -1)
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
		_env(commtoken);




		_write(shellprompt);







	}


	free(command);
return(0);
}
