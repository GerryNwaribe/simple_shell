#include "main.h"

/**
 * _strdup - function
 *
 * @str: input
 * Return: pointer
 */

char *_strdup(char *str)
{
	char *b;
	size_t idx, m;

	if (str == NULL)
		return (0);

	idx = _strlen(str);

	b = malloc((idx + 1) * sizeof(char));
	if (b == NULL)
		return (0);

	for (m = 0; m < idx; m++)
		b[m] = str[m];

	return (b);
}
