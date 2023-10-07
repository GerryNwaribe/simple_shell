#include "main.h"

/**
 * _strcpy - copy a string from 'src' to 'dest'
 * @dest: destination string
 * @src: source string
 * Return: Pointer to 'dest'.
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for (; x < l; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
