#include "main.h"

/**
 * _is_semicolon - checks if semicolon is part of the string.
 * @gtln: the string to be checked.
 * Return: 1 if found and 0 otherwise
 */
int _is_semicolon(string gtln)
{
	(void)_head_;

	if (strchr(gtln, ';'))
		return (1);

	return (0);
}
