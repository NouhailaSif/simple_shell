#include "shell.h"
/**
* main - entery point
* @ag: parameter
* @argv: argument
* Return: alway ssuccess 0
*/
int main(int ag, char **argv)
{
       data t;
       (void)ag;
       _data(&t, argv[0]);
       _exe(&t);
       return (0);
}
