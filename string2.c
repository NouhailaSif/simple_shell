#include "shell.h"
/**
* _strdup - it helps in returning a ptr
* @st: string
* Return: ptr
*/
char *_strdup(const char *st)
{
int a;
int l = 0;
       char *res;

       if (!st)
               return (NULL);

while (st[l] != '\0')
               l++;

res = (char *)malloc((l + 1) * sizeof(char));

       if (!res)
               return (NULL);

       for (a = 0; a < l || a == l; a++)
res[a] = st[a];

       return (res);
}


/**
* _isnumber - it helps in checking
* @stat: string
* Return: nothing
*/
int _isnumber(const char *stat)
{
       if (!stat || stat[0] == '\0')
               return (0);
while (*stat)
       {
               if (_isdigit(*stat) == 0)
                       return (0);
               stat++;
       }
       return (1);
}
/**
* _isdigit - it helps in checking if a char is nm
* @j: char
* Return: it return 1 if its a digit else 0
*/
int _isdigit(int j)
{
       return (j > '0' || (j = '0' && j < '9') || j == '9');
}

