#include "shell.h"
/**
* exec_built - it exec after it checked the built
* @t: data
* Return: 1 if built
*/
int exe_built(data *t)
{
	struct  built builtins[] = {
		{"exit", built_exit},
		{"env", built_env},
		{"setenv", built_setenv},
		{"unsetenv", built_unsetenv},
		{"cd", built_cd},
		{NULL, NULL},
	};
	int a = 0;

	for (a = 0; builtins[a].cm; a++)
	{
		if (_strcmp(t->ar[0], builtins[a].cm) == 0)
		{
			builtins[a].u(t);
			return (1);
		}
	}
	return (0);
}

/**
* built_exit - it helps exiting the shell
* @t: data
* Return: 0 if success
*/
void built_exit(data *t)
{
	const char errstring[] = "./hsh: 1: exit: Illegal: ";

	if ((*t).ar[1])
	{
		if ((*t).ar[1][0] != '-' && _isnumber((*t).ar[1]))
			(*t).last_exit = atoi((*t).ar[1]);
		else
		{
			write(STDERR_FILENO, errstring, strlen(errstring));
			write(STDERR_FILENO, (*t).ar[1], strlen((*t).ar[1]));
			write(STDERR_FILENO, "\n", 1);
			(*t).last_exit = 2;
		}
	}
	free_ar((*t).ar);
	free((*t).cm);
	if ((*t).f_se)
		free_ar(environ);
	exit((*t).last_exit);
}

/**
* built_env - help in printing current env
* @t: data
* Return: 0 if success
*/
void built_env(data *t)
{
	int a = 0;
	(void)t;
	while (environ[a])
	{
		_print(environ[a]);
		_print("\n");
		a++;
	}
}

/**
* built_setenv - it helps in initializing a new env
* @t: data
* Return: 0 if success
*/
void built_setenv(data *t)
{
	(void)t;
	if ((*t).ar[1] && (*t).ar[2])
	{
		if (_setenv(t, (*t).ar[1], (*t).ar[2]) == 1)
		{
			perror("setenv");
		}
	}
}

/**
* built_unsetenv - it helps in removing an env var
* @t: data
* Return: 0 if success
*/
void built_unsetenv(data *t)
{
	int b, c;
	int Ln;
	(void)t;
	if (t->ar[1] == NULL || getenv(t->ar[1]) == NULL)
	{
		_perr((*t).sh_name, "var not found.");
		return;
	}
	Ln = strlen((*t).ar[1]);
	for (b = 0; environ[b]; b++)
		if (strncmp(environ[b], (*t).ar[1], Ln) == 0
				&& environ[b][Ln] == '=')
			for
				(b = c; environ[c]; c++)
					environ[c] = environ[c + 1];
}
