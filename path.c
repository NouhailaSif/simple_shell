#include "shell.h"
char **environ;

/**
* _getenv - Retrieve the value of an environment variable
* @nom: Variable name
* Return: Value of the environment variable if found, NULL otherwise
*/
char *_getenv(char *nom)
{
int a = -1;
size_t nom_l;

   if (!nom || *nom == '\0')
       return (NULL);
   if (!environ)
       return (NULL);

nom_l = _strlen(nom);

while (environ[++a])
   {
       if (_strncmp(environ[a], nom, nom_l) == 0 && environ[a][nom_l] == '=')
       {
           return (environ[a] + nom_l + 1);
       }
   }
   return (NULL);
}

/**
* _whix - Locate the executable file
* @t: Data structure
* Return: 0 if successful, -1 otherwise
*/
int _whix(data *t)
{
   char *tok;
   char *p;
size_t tok_l;
int look = -1;
   char *ps = malloc(_strlen(_getenv("PATH") ? _getenv("PATH") : "") + 1);

   if (_getenv("PATH") == NULL)
goto out;

   if (ps == NULL)
goto out;
   _strcpy(ps, _getenv("PATH"));

tok = strtok(ps, ":");
while (tok)
   {
tok_l = _strlen(tok) + _strlen(t->ar[0]) + 2;
       p = malloc(tok_l);
       if (!p)
           return (look);
       _strcpy(p, tok);
       _strcat(p, "/");
       _strcat(p, t->ar[0]);
       if (access(p, F_OK) == 0)
       {
           free(t->ar[0]);
           t->ar[0] = _strdup(p);
           free(p);
           look = 0;
           break;
       }
       free(p);
tok = strtok(NULL, ":");
   }

out:
free(ps);
   return (look);
}

/**
* new_entery - Initialize a new environment entry
* @nom: Variable name
* @v: Variable value
* Return: New environment entry
*/
char *new_entery(char *nom, char *v)
{
size_t N_l = strlen(nom) + strlen(v) + 2;
   char *n_entery = malloc(N_l);

   if (!n_entery)
       return (NULL);

strcpy(n_entery, nom);
strcat(n_entery, "=");
strcat(n_entery, v);

   return (n_entery);
}

/**
* new_env - Initialize a new environment variable
* @nom: Variable name
* @v: Variable value
* Return: New environmentarray
*/
char **new_env(char *nom, char *v)
{
int env_l = 0;
int a = 0;
   char *n_entery;
   char **n_env;

while (environ[env_l])
env_l++;

n_entery = new_entery(nom, v);
   if (!n_entery)
       return (NULL);

n_env = _getenv(nom) != NULL ? malloc((env_l + 1) * sizeof(char *)) : malloc((env_l + 2) * sizeof(char *));
   if (!n_env)
   {
free(n_entery);
       return (NULL);
   }

   for (a = 0; environ[a]; a++)
   {
n_env[a] = malloc(strlen(environ[a]) + 1);
       if (!n_env[a])
       {
free_ar(n_env);
free(n_entery);
           return (NULL);
       }
strcpy(n_env[a], environ[a]);
   }

   if (_getenv(nom) == NULL)
   {
n_env[env_l] = n_entery;
n_env[env_l + 1] = NULL;
   }
else
n_env[env_l] = NULL;

   return (n_env);
}

/**
* _setenv - Initialize an environment variable
* @t: Data structure
* @nom: Variable name
* @v: Variable value
* Return: 0 if successful, -1 otherwise
*/
int _setenv(data *t, char *nom, char *v)
{
   char **n_env;

   if (nom == NULL || v == NULL)
       return (-1);

n_env = new_env(nom, v);
   if (n_env == NULL)
       return (-1);

   environ = n_env;
   t->f_se = 1;

   return (0);
}
