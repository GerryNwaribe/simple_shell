#include "main.h"

/**
 * _putchar - 
 * @c:
*/
int _putchar(char c)
{
    return (write(STDOUT_FILENO, &c, 1)); /* STDOUT_FILENO is part of unistd.h */
}
