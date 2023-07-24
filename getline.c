#include "shell.h"
/**
* _helper_get - the function that help getline
* @Lp: string
* @n: parameter
* Return: 0 if success
*/
int _helper_get(char **Lp, size_t *n)
{
       if(Lp == NULL || *n == 0)
       {
               *n = 128;
               *Lp = calloc(*n, sizeof(char));
               if (*Lp == NULL)
               return (-1);
       }
       return (0);
}

/**
* my_getline - reads characters from the input stream
* @Lp: string
* @n: paramter
* @stream: File
* Return: 0 if success
*/
ssize_t my_getline(char **Lp, size_t *n, FILE *stream)
{
       size_t p = 0;
       ssize_t bytesR = 0;
       size_t nS;
       static size_t bufS;
       static char buf[READ_BUFFER_SIZE];
       static size_t bufP;
       char *nB;
       if (!Lp || !n || !stream || _helper_get(Lp, n) == -1)
               return (-1);
       while (1)
       {
               if (bufP > bufS || bufP == bufS)
               {
                       bytesR = read(fileno(stream), buf, READ_BUFFER_SIZE);
                       if (bytesR < 0 || (bytesR == 0 && p == 0))
                               return (-1);
                       else if (bytesR < 0 || bytesR == 0)
                               break;
                       bufS = bytesR;
               }
  if (p > *n - 1 || p == *n - 1)
               {
                       nS = *n * 2;
                       nB = realloc(*Lp, nS);
                       if (!nB)
                               return (-1);
                       *Lp = nB;
                       *n = nS;
               }
               (*Lp)[p++] = buf[bufP++];
               if ((*Lp)[p  - 1] == '\n')
                       break;
       }
       (*Lp)[p] = '\0';
       return (p);
}
