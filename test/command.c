#include "main.h"
/**
 * 
 * 
*/
void execute(char *argv[], char **env)
{
   
    char *actual_command = NULL;
   
   
    if (argv[0] != NULL)
    {
        actual_command = argv[0];
    }
    if ((execve(actual_command, argv, env)) == -1)
    {
        perror("error");
    }
}