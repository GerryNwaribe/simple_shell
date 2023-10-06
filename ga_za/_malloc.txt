#include "main.c"

/**
 * _malloc_bffr -
 * @x:
 * Return:
*/
char *_malloc_bffr(size_t x)
{
    char *bffr;

    bffr = malloc(sizeof(char) * x);
    if (bffr == NULL)
    {
        exit(EXIT_FAILURE);
    }       
    
    return (bffr);
}
