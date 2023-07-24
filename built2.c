#include "shell.h"
/**
* built_cd - it helps in changing dir
* @t: data
* Return: 0 if success
*/
void built_cd(data *t)
{
	char *d = (*t).ar[1];
	char cwd[256];
	if (!getcwd(cwd, sizeof(cwd)))
		perror("getcwd() error");
	_setenv(t, "PWD", cwd);
	if (d == NULL)
		d = _getenv("HOME");
	if (chdir(d) == -1)
		perror("cd");
	else
	{
		_setenv(t, "OLDPWD", _getenv("PWD"));
		if (!getcwd(cwd, sizeof(cwd)))
			perror("getcwd() error");
		_setenv(t, "PWD", cwd);
	}
}
