#include "main.h"
/**
 * 
 * 
*/
int _and(char *cmd_one, char *cmd_two)
{
    char *one;
    char *two;
    char buffer = _BFFSZ;

     one = (int *)malloc(sizeof(int));
    two = (int *)malloc(sizeof(int));
    
    if (one == NULL || two == NULL) 
    {
        perror("Error: Malloc failed");
        exit(99);
    }
    
    one = &cmd_one;
    two = &cmd_two;

    buffer = malloc(sizeof(char) * buffer);
    if (buffer == NULL)
    {
        perror("Error: Malloc failed");
        exit(99);
    }
    if (one == 0 || two == 0)
    return (1);

    if (*one > 0 && *two == 0 || *one == 0 && *two > 0)
    {
    return (-1);
    }
    else
    {
        return (1);
    }
    free(one);
    free(two);
    free(buffer);
    return (1);
}

int main() 
{
    int result1 = _and(0, 0);
    int result2 = _and(0, 1); 
    int result3 = _and(1, 0); 
    int result4 = _and(1, 1); 

    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);
    printf("Result 3: %d\n", result3);
    printf("Result 4: %d\n", result4);

    return 0;
}