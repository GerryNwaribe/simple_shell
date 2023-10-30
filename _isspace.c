#include "main.h"

/**
 * _isblnk - Checks if a string contains only whitespace characters.
 * @str: The string to be checked.
 * Return: 1 if the string contains only whitespace characters, 0 otherwise.
 */
int _isblnk(char *str)
{
	int i;

	(void)_head_;

	for (i = 0; str[i]; i++)
		if (!isspace((unsigned char)str[i]))
			return (0);   /* Found a non-whitespace character */

	return (1);   /* All characters are whitespace */
}
