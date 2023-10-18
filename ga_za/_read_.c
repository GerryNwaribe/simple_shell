#include "main.h"

/**
 *  _getline - Read a line of text from a file descriptor, allocate memory
 * @getlineptr: Pointer to a pointer to the line buffer.
 * @bffsz: Pointer to the buffer size.
 * @f_d: File descriptor to read from.
 * Return: returns the number of characters read
 */
ssize_t _read_Getline(char **getlineptr, size_t *bffsz, int f_d)
{
 /*   ssize_t rd;
   
        rd = read(f_d, buffr + total_rd, *bffsz - total_rd);
        if (rd < 0)
        {
            perror("Error: Can't read from file");
            free(buffr);
            exit(98);
        }
        else if (rd == 0)
        {
            free(buffr);
            return (-1);
        }
        total_rd += rd;

   

    return (total_rd);*/
    return (0);
}