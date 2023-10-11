#include "main.h"
/**
 * _getline -
 * @str:
 * @a:
 * @stream:
 * Return:
 * 
*/
ssize_t _getline(char **str, size_t *a, FILE *stream)
{
    static char *buffer, *buffer2;
    static ssize_t bufsize = BUFSIZE;
    int num_char = 0, index;
    char readd;

    *str = buffer;
    buffer = malloc(sizeof(char *) * bufsize);
    if (buffer == NULL)
    {
        perror("sh");
        free(buffer);
        return (-1);
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
        buffer2 = malloc(sizeof(char *) * (bufsize * 2));
        if (buffer2 == NULL)
        {
            perror("sh");
            free(buffer2);
            return (-1);
        }
    
        for (index = 0; index < num_char; index++)
        {
            buffer2[index] = buffer[index];

        }
        /*free(buffer2);*/
        free(buffer);
        buffer = buffer2;
        bufsize *= 2;
    }
    buffer[num_char++] = readd;
    }
    buffer[num_char] = '\0';

    if (bufsize == 0 && num_char == -1)
    {
        free(buffer);
        return (-1);
    }
    else
    return (bufsize);
}
