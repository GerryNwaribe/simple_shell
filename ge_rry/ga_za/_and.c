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

    tokens = _tokenization(buffer, "&&");
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

    if (*one > 0 && *two == 0 || *one == 0 && *two > 0)
    {
        free(one);
        free(two);
        return (-1);
    }
    else
    {
        free(one);
        free(two);
        return (1);
    }
}
