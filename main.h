#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define DELIM "\n\r\a\"\t"
#define _sizeof(data_type)(char *)(&data_type + 1) - (char *)(&data_type)

extern char **environ;

/* Shell Mode */
void interactive_mode(void);
void non_interactive_mode(void);

/* Interactive Mode */
char *read_stdin(void);
char **tokenize_stdin(char *Stdin);
int execute(char **argv);

int _process(char **argv);

/* Non Interactive Mode */
char *read_strm(void);

/*Built ins*/
int _cd(char **argv);
int endprog(char **argv);
int _env(char **argv);
int _help(char **argv);

/* Others */
void _write(char *str);
#endif
