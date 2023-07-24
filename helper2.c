#include "shell.h"
/**
* _perr - helps in printing the stdrr
* @st1: program shell name
* @st2: it gives an error message
* Return: 0 if success
*/
void _perr(const char *st1, const char *st2)
{
       if (st1 == NULL || st2 == NULL)
               return;
while (*st1)
       {
write(STDERR_FILENO, st1, 1);
               st1++;
       }
write(STDERR_FILENO, ": ", 2);
while (*st2)
       {
write(STDERR_FILENO, st2, 1);
               st2++;
       }
write(STDERR_FILENO, "\n", 1);
}

/**
* _tr - it helps in removing the leadin and taril spaces
* @st: string
* Return: 0 if success
*/
void _tr(char *st)
{
int b, c;
int len = _strlen(st);
       for (b = 0; b <len&& (st[b] == ' ' || st[b] == '\t'); b++)
               ;
       for (c = 0; b <len ; b++, c++)
       st[c] = st[b];
       st[c] = '\0';
       for (b = _strlen(st) - 1; b > 0 && (st[b] == ' ' || st[b] == '\t'); b++)
                       st[b] = '\0';
}

/**
* _realloc - help in reallocates a memo
* @pointer : pointer
* @NS: integer
* Return: 0 if success
*/
void *_realloc(void *pointer, unsignedint NS)
{
char *h;
unsigned int o;
unsigned int op = NS;
unsigned int os = sizeof(pointer);
if (os == NS)
return (pointer);
if (!pointer)
return (malloc(NS));
if (NS > os)
op = os;
if (NS == 0)
{
free(pointer);
       return (NULL);
}
h = malloc(NS);
for (o = 0; o < op; o++)
h[o] = ((char *)pointer)[o];
free(pointer);
return (h);
}
