#include "main.h"

/**
 * _getline -
 * @getlineptr:
 * @bffsz:
 * @f_d:
 * Return:
 *
 */
ssize_t _getline(char **getlineptr, size_t *bffsz, int f_d)
{
    char *buffr = NULL;
    ssize_t total_rd = 0;
    ssize_t rd;

    if (*bffsz == 0) {
        *bffsz = _BFFSZ;
    }

    buffr = (char *)malloc(*bffsz);
    if (buffr == NULL) {
        perror("Error: Malloc failed");
        exit(99);
    }
    *getlineptr = buffr;

    do {
        if (total_rd == *bffsz) { 
            *bffsz *= 2;
            buffr = (char *)realloc(buffr, *bffsz);
            if (buffr == NULL) {
                perror("Error: Realloc failed");
                exit(99);
            }
            *getlineptr = buffr;
        }

        rd = read(f_d, buffr + total_rd, *bffsz - total_rd);
        if (rd < 0) {
            perror("Error: Can't read from file");
            free(buffr);
            exit(98);
        } else if (rd == 0) { 
            free(buffr);
            return -1;
        }
        total_rd += rd;

    } while (rd > 0 && buffr[total_rd - 1] != '\n');

    buffr[total_rd] = '\0'; 

    return total_rd;
}



/* char buffer[1024];
    ssize_t i = 0, res;
    char *new_getline_ptr = NULL;

    if (*getlineptr == NULL || *bffsz == 0)
    {
        *bffsz = 1024;                                           Initial size of buffer
        *getlineptr = (char *)malloc(sizeof(char) * (*bffsz));
        if (*getlineptr == NULL)
            return (-1);
    }

    while ((res = read(f_d, buffer, sizeof(buffer))) > 0)
    {

        if (i + res >= *bffsz)                  Buffer is full, need to allocate more space
        {
            *bffsz *= 2;
            new_getline_ptr = (char *)realloc(*getlineptr, *bffsz);
            if (new_getline_ptr == NULL)
                return -1;
            *getlineptr = new_getline_ptr;
        }


        if (i + res < *bffsz)
        {
            strncpy(*getlineptr + i, buffer, res);
            i += res;
        }

        strcpy(*getlineptr + i, buffer);
        i += res;

        if (strchr(buffer, '\n') != NULL)
            break;                      Newline reached, end of line
    }

    if (i == 0 && res == 0)
        return (-1);                 Error occurred during read

    (*getlineptr)[i] = '\0';        Null-terminate the string

    return (i);                   Return number of characters read */
