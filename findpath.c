#include "main.h"

/**
 */


char *findpath(char *command, char *argv[], char *env[])
{
	char *pathname = NULL, *token = NULL, filepath[1024], *duplicate = NULL;
	struct stat statbuf;

	if (check_command(command) == 4)
		return (command);

	pathname = getenv("PATH");
	duplicate = strdup(pathname);
	token = strtok(duplicate, ":");

	while(token != NULL) {
		
		strcpy(filepath, token);
		strcat(filepath, "/");
		strcat(filepath, command);
		strcat(filepath, "\0");
		printf("%s \tstat -> %d\n", filepath,stat(filepath, &statbuf) );
		
		if (stat(filepath, &statbuf) == 0)
		{
			free(duplicate);
			strcpy(argv[0], filepath);
			_fork(argv, env);
			empty(argv);
			free(argv[0]);
			return (NULL);
		}
		else
			token = strtok(NULL, ":");
	}
	free(duplicate);
	perror("Error");

	free(argv[0]);
	return (NULL);
}

