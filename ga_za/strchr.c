#include "main.h"

/**
 * _strchr -
 * @s:
 * @c:
 * Return:
 * 
 */
int _strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (1);
	}

	return (0);
}
