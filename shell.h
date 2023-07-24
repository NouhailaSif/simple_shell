#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

extern char **environ;
#define PMPT "#csisfun$ "


/**
* struct data - ithelps in holding data
* @ar: its an array of toksthat help in execve
* @cm: command
* @sh_name: shell program name
* @last_exit: last exit
* @f_se: 1 if user didexecution
*/
typedef struct data
{
       char **ar;
       char *cm;
const char *sh_name;
int last_exit;
int f_se;
} data;

/**
* struct built - helps in holding main data
* @cm: help in building a command
* @u: help in functioning the command
*/
typedef struct built
{
const char *cm;
void (*u)(data *t);
} builtins;
int exe_built(data *t);
void built_exit(data *t);
void built_env(data *t);
void built_setenv(data *t);
void built_unsetenv(data *t);
void built_cd(data *t);
void _print(const char *stri);
void free_ar(char **arr);
void split(data *t, const char *delm);
void _data(data *t, const char *sh_name);
void read_command(data *t);
void _perr(const char *st1, const char *st2);
void _tr(char *st);
void *_realloc(void *pointer, unsignedint NS);
void s_process(data *t);
void hand_sig(intsig);
void _exe(data *t);
char *_getenv(char *nom);
int _whix(data *t);
int _setenv(data *t, char *nom, char *v);
unsigned int _strlen(char *st);
int _strcmp(const char *st1, const char *st2);
int _strncmp(const char *st1, const char *st2, int m);
char *_strcpy(char *de, const char *sr);
char *_strcat(char *de, const char *sr);
char *_strdup(const char *st);
int _isnumber(const char *stat);
int _isdigit(int j);
#define READ_BUFFER_SIZE 1024
ssize_tmy_getline(char **Lp, size_t *n, FILE *stream);


#endif

