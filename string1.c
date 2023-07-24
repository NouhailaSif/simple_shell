#include "shell.h"

/**
* _strlen - it helps in returning nbers
* @st: string
* Return: 0 if success
*/

unsigned int _strlen(char *st)
{
unsigned int a;

       for (a = 0; st[a] != '\0'; a++)
               ;
       return (a);
}


/**
* _strcmp - helps in comparing 2 strings
*
* @st1: string
* @st2: string
*
* Return: 0 if success
*/
int _strcmp(const char *st1, const char *st2)
{
int a;

       for (a = 0; st1[a] != '\0' && st2[a] != '\0'; a++)
       {
               if (st1[a] != st2[a])
               {
                       return ( st1[a] - st2[a]);

               }
       }

       return (st1[a] - st2[a]);
}
/**
* _strncmp - it helps in comparing
*
* @st1: string
* @st2: string
* @m: integer
* Return: nothing
*/
int _strncmp(const char *st1, const char *st2, int m)
{
int a;

       for (a = 0; st1[a] != '\0' && st2[a] != '\0'; a++)
       {

               if (st1[a] - st2[a])
		{
			return (st1[a] - st2[a]);
		}
	}
	if (a == m)
	{
		return (0);
	}
	else
	{
		return (st1[a] - st2[a]);
	}
}

/**
* _strcpy - it helps in copying
* @de: string
* @sr: string
* Return: nothing
*/
char *_strcpy(char *de, const char *sr)
{
int l;

       for (l = 0; sr[l] != '\0'; ++l)
       {
               de[l] = sr[l];
       }
       de[l] = '\0';
       return (de);
}
/**
* _strcat - it helps in appending
*
* @de: string
* @sr: string
*
* Return: nothing
*/
char *_strcat(char *de, const char *sr)
{
       char *res = de;

while (*de != '\0')
               de++;

while (*sr != '\0')
       {
               *de = *sr;
               de++;
               sr++;
       }
       *de = '\0';

       return (res);
}

