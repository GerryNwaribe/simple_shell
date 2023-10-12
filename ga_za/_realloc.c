#include "main.h"

/**
 * _realloc - A memory realocator to any data type.
 * 
 * 
*/
void *_realloc(void *ptr, size_t new_sz)
{
    if (!(ptr))
    {
        ptr = malloc(new_sz);
        return (ptr);
    }
    if (!(new_sz) && ptr)
        free(ptr);
    



    return NULL;


}
