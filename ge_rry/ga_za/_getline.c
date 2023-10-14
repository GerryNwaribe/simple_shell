#include "main.h"

/**
 * _getline -
 * @str:
 * @a:
 * @f_d:
 * Return:
 *
 */
ssize_t _getline(char **lineptr, size_t *n, int f_d)
{
    char buffer;
    ssize_t i = 0, res = 0;
    /*int fd = 0;*/

    /*(void)f_d;*/
    if (*lineptr == NULL || *n == 0)
    {
        *n = 100; /* Initial size of buffer */

        *lineptr = malloc(*n);
        if (*lineptr == NULL)
            return -1;
    }

    while (1)
    {
        res = read(f_d, &buffer, 1);
        printf("%li", res);
        if (res == -1)
        {

            free(*lineptr);
            return (-1); /* Error reading from file descriptor */
        }
        else if (res == 0)
            break; /* End-of-file reached */

        else
        {
            (*lineptr)[i++] = buffer;

            if (i == *n) /* Buffer is full, need to allocate more space */
            {

                *lineptr = _realloc(*lineptr, *n, *n * 2);
                if (*lineptr == NULL)
                    return (-1);
            }

            if (buffer == '\n')
                break; /* Newline reached, end of line */
        }
    }
    printf("%li", i);
    (*lineptr)[i] = '\0'; /* Null-terminate the string */
    return (i);           /* Return number of characters read */
}

/*ssize_t _getline(char **str, size_t *a, FILE *stream)
{
    static char *buffer, *buffer2;
    static ssize_t bufsize = _bffsz;
    int num_char = 0, index;
    char readd;

    *str = buffer;
    buffer = malloc(sizeof(char *) * bufsize);
    if (buffer == NULL)
    {
        perror("Error");
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
        free(buffer2);
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
}*/
