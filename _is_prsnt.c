#include "main.h"

/**
 * _is_prsent - similar to strcmp, Takes str & cmp with '_str'
 * @str: The string to be compared.
 * Return: 0 if found and 1 otherwise.
 */
int _is_prsent(string str)
{
	int x;
	char *_str[] = {"cd", "env", "exit", "setenv", "unsetenv", "alias", NULL};

	(void)_head_;
	for (x = 0; _str[x]; x++)
	{
		if (!(strcmp(str, _str[x])))
			return (0);
	}

	return (1);
}
