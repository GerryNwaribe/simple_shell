#include "main.h"

/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: The difference between the first differing characters in s1 and s2,
 *         or 0 if both strings are equal.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;

/* Compare chars of s1 and s2 until a difference or end of both strings */
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{	/* Return the difference between the differing characters. */
			return (s1[i] - s2[i]);
		}
		i++;
	}

	return (0); /* Return 0 if both strings are equal up to this point. */
}
