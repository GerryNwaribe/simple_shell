#include "main.h"
/**
 * 
 * 
*/
int _and(char *cmd_one, char *cmd_two)
{
   char *one;
    char *two;
    char buffer[_BFFSZ];
    char **tokens;

    tokens = _tokenization(buffer, "||");
    one = malloc(strlen(cmd_one) + 1);
    two = malloc(strlen(cmd_two) + 1);
    
    if (one == NULL || two == NULL) 
    {
        perror("Error: Malloc failed");
        return (-1);
    }
    
    _strcpy(one, cmd_one);
    _strcpy(two, cmd_two);

    if (tokens == NULL)
        return (1);
    if (strcmp(one, two) == 0)
    return(0);
    
        if (*one > 0 && *two == 0 || *one == 0 && *two > 0 || *one == 0 && *two == 0)
        {
            free(one);
            free(two);
            return (-1);
         }

    pid_t pid1 = fork();
    int status;
    if(pid1 == 0)
    {
    
        free(one);
        free(two);
        return (1);
    }
}



/* pid_t pid;
    int status;
    char buffer[_BFFSZ];
    char **tokens;

    tokens = _tokenization(buffer, "||");

    pid = fork();
    if (pid < 0) 
    {
        perror("Error: Fork failed");
        return -1;
    } 
    else if (pid == 0) 
    {
        char *args[] = {cmd_one, NULL};
        if (execvp(cmd_one, args) == -1) 
        {
            perror("Error: Exec failed");
            exit(1);
        }
    } 
    else 
    {
        if (waitpid(pid, &status, 0) == -1) 
        {
            perror("Error: Waitpid failed");
            return -1;
        }
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) 
        {
            return WEXITSTATUS(status);
        }
    }

    pid = fork();
    if (pid < 0) 
    {
        perror("Error: Fork failed");
        return -1;
    } 
    else if (pid == 0) 
    {
        char *args[] = {cmd_two, NULL};
        if (execvp(cmd_two, args) == -1) 
        {
            perror("Error: Exec failed");
            exit(1);
        }
    } 
    else 
    {
        
        if (waitpid(pid, &status, 0) == -1) 
        {
            perror("Error: Waitpid failed");
            return -1;
        }
        return WEXITSTATUS(status);
    }*/
