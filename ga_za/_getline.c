#include "main.h"

/**
 * _getline -
 * @getlineptr:
 * @n:
 * @f_d:
 * Return:
 *
 */
ssize_t _getline(char **getlineptr, size_t *bffsz, int f_d)
{
    char buffer[1024];
    ssize_t i = 0, res;
    char *new_getline_ptr;

    if (*getlineptr == NULL || *bffsz == 0)
    {
        *bffsz = 1024; /* Initial size of buffer */
        *getlineptr = (char *)malloc(sizeof(char) * (*bffsz));
        if (*getlineptr == NULL)
            return (-1);
    }

    while ((res = read(f_d, buffer, sizeof(buffer))) > 0)
    {
        
       if (i + res >= *bffsz)      /*Buffer is full, need to allocate more space */
        {
            *bffsz *= 2;
            new_getline_ptr = (char *)realloc(*getlineptr, *bffsz);
            if (new_getline_ptr == NULL)
                return -1;
        }
         *getlineptr = new_getline_ptr;
         
         if (i + res < *bffsz)
        {
            strncpy(*getlineptr + i, buffer, res);
            i += res;
        }
        
        strcpy(*getlineptr /*+ i*/, buffer);
        i += res;

        if (strchr(buffer, '\n') != NULL)
            break;  /* Newline reached, end of line */
    }

    if (i == 0 && res == 0)
    {
        return -1;  /* Error occurred during read */
    }

    (*getlineptr)[i] = '\0'; /* Null-terminate the string */
    
    return i;             /* Return number of characters read */
}
