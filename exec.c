#include "shell.h"
#include <signal.h>
/**
* s_process - its starting a new proc
* @t: data
* Return: 0 if success
*/
void s_process(data *t)
{
       pid_t nono;
       int stat = 0;
	nono = fork();

       if (nono == -1)
               goto free;
       if (nono == 0 && execve((*t).ar[0],
                               (*t).ar, NULL) == -1)
               goto free;
       else if (wait(&stat) == -1)
               goto free;
       if (WIFEXITED(stat))
               (*t).last_exit = WEXITSTATUS(stat);
       return;
free:
       perror((*t).sh_name);
       free_ar((*t).ar);
       free((*t).cm);
       exit(EXIT_FAILURE);
}

/**
* hand_sig - help in signaling the hand fun
* @sig: integer
* Return: 0 if success
*/
void hand_sig(int sig)
{
       (void)sig;
       exit(EXIT_FAILURE);
}

/**
* _exe - it helps in executing the command
* @t: data
* Retrun: 0 if success
*/
void _exe(data *t)
{
       const char pmt[] = PMPT;
               signal(SIGINT, hand_sig);
while (1)
       {
               if (isatty(STDIN_FILENO))
                       _print(pmt);
               read_command(t);
               if (_strlen((*t).cm) !=0)
               {
                       split(t, " ");
                       if (exe_built(t) == 0)
                       {
                               _whix(t);
                               if (access((*t).ar[0], F_OK) == -1)
                               {
                                       perror((*t).sh_name);
                               }
                               else
                               {
                                       s_process(t);
                               }
                       }
                       free_ar((*t).ar);
               }
               free((*t).cm);
       }
}
