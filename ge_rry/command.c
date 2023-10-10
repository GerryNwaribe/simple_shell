#include "main.h"
/**
 * 
 * 
*/
void execute(char *argv[], char **env)
{
   
    char *actual_command = NULL;
   char *command = NULL;
   
    if (argv[0] != NULL)
    {
        command = argv[0];
        actual_command = locate(command);
    if (actual_command != NULL)
    {
    if ((execve(actual_command, argv, env)) == -1)
    {
        perror("error");
    }
   free(actual_command);
    }
    }


}