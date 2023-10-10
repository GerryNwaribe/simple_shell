#include "main.h"

/**
 * _strncmp -
 * @str1: First string.
 * @str2: Second string.
 * Return: A difference if unequal char and 0 if non found.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
    size_t i = 0;

    while (str1[i] != '\0' && str2[i] != '\0' && i < n)
    {
        if (str1[i] != str2[i])
        {
            return (str1[i] - str2[i]);
        }
        i++;
    }

    return (0);
}
