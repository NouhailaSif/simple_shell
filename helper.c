#include "shell.h"
/**
* _print - help in printing a string to standard output
* @stri: string
* Return: 0 if success
*/
void _print(const char *stri)
{
       if (stri == NULL)
               return;
       while (*stri)
       {
               write(STDOUT_FILENO, stri, 1);
               stri++;
       }
}

/**
* free_ar - helps in freeing an array of a ptr
* @arr: array of ptr
* Return: 0 if success
*/

void free_ar(char **arr)
{
       int a;
       if (arr == NULL)
               return;
       for (a = 0; arr[a]; a++)
       {
               free(arr[a]);
               arr[a] = NULL;
       }
       free(arr);
}
/**
* split - helps in giving string by delm
* @t: data
* @delm: parameter
* Return: 0 if success
*/
void split(data *t, const char *delm)
{
       int ntok = 0;
       char *tok;
       (*t).ar = malloc(2 * sizeof(char*));
       if ((*t).ar == NULL)
       {
     free((*t).cm);
               perror((*t).sh_name);
               exit(EXIT_FAILURE);
       }
       (*t).ar[0] = NULL;
       (*t).ar[1] = NULL;
       tok = strtok((*t).cm, delm);
       while (tok)
       {
               (*t).ar = realloc((*t).ar, (ntok + 2) * sizeof(char *));
               if ((*t).ar == NULL)
                       goto free;
               (*t).ar[ntok] = _strdup(tok);
               if ((*t).ar[ntok] == NULL)
                       goto free;
               ntok++;
                       tok = strtok(NULL, delm);
       }
       (*t).ar[ntok] = NULL;
       return;
free:
       free_ar((*t).ar);
       free((*t).cm);
       perror((*t).sh_name);
       exit(EXIT_FAILURE);
}

/**
* _data - helps in intializing the data
* @t: data
* @sh_name: string
* Return: 0 if success
*/

void _data(data *t, const char *sh_name)
{
       (*t).cm = NULL;
       (*t).ar = NULL;
       (*t).sh_name = sh_name;
       (*t).last_exit = EXIT_SUCCESS;
       (*t).f_se = 0;
}

/**
* read_command - helps in getting cmd from pmpt
* @t: data
* Return: 0 if success
*/
void read_command(data *t)
{
       ssize_t Nr;
       size_t x = 0;
       int a = 0;
       Nr = my_getline(&t->cm, &x, stdin);
       if (Nr == -1)
       {
               free((*t).cm);
               exit(EXIT_SUCCESS);
       }
       (*t).cm[Nr - 1] = '\0';
       _tr((*t).cm);
       for (a = 0; (*t).cm[a] != '\0'; a++)
       {
               if ((*t).cm[0] == '#' ||
                               ((*t).cm[a] == '#' && (*t).cm[a - 1] == ' '))
               {
                       (*t).cm[a] = '\0';
                       break;
               }
       }
       _tr((*t).cm);
}
