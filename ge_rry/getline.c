#include "main.h"
/**
 * 
 * 
*/
ssize_t _getline(char **str, size_t *a, FILE *stream)
{
    char *buffer;
    char *buffer2;
    ssize_t bufsize = 0;
    int num_char = 0;
    char readd;
    int index;
    buffer = malloc(sizeof(char *) * *buffer);
    if (buffer == NULL)
    {
        perror("sh");
        free(buffer);
        return(NULL);
    }
    while (1)
    {
        readd = getchar();
        if (readd == -1 || readd == '\n') 
        {
            break;
        }
    
    if (num_char >= bufsize - 1)
    {
        buffer2 = malloc(sizeof(char *) * *buffer);
        if (buffer2 == NULL)
        {
            perror("sh");
            free(buffer2);
            return(NULL);
        }
    
        for (index = 0; index < num_char; index++)
        {
            buffer2[index] = buffer[index];

        }
        free(buffer2);
        free(buffer);
        buffer = buffer2;
    }
    buffer[num_char++] = readd;
    }
    buffer[num_char] = '\0';

    if (bufsize == 0 && num_char == -1)
    {
        free(buffer);
        return (NULL);
    }
    else
    return (buffer);
}
