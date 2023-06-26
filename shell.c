#include "main.h"


/* Global variable to indicate if SIGINT was received */
volatile sig_atomic_t interrupted = 0;

/* Signal handler for SIGINT */
void handle_sigint(int signum)
{
    interrupted = 1;
}


int main(int argc, char *argv[], char *env[])
{
	char *shellprompt = "shell $: ";
	char *command = NULL;
	size_t n = 0;
	    signal(SIGINT, handle_sigint);


	_write(shellprompt);
	while (!interrupted)
	{
		if (getline(&command, &n, stdin) == -1)
		{
			free(command);
			return (-1);
		}
		
		check_command(command);
		_write(shellprompt);







	}


	free(command);
return(0);
}
