#include "main.h"
#include <stdio.h>

/**
 * _strcat - Concatenates two strings strcat()
 *
 * @dest: The destination string to which src will be appended.
 * @src: The source string that will be appended to dest.
 *
 * Return: A pointer to the modified dest string.
 */

char *_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
    {
        i++;
    }

    if (i + _strlen(src) >= sizeof(dest))
    {
        return NULL;
    }

    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';

    return dest;
}

