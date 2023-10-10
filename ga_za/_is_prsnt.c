#include "main.h"

/**
 * _is_prsent -
 * @str:
 * Return:
 */
int _is_prsent(string str)
{
	int x;
	char *_str[] = {"cd", "env", "exit", NULL};

	for (x = 0; _str[x]; x++)
	{
		if (!(_strcmp(str, _str[x])))
		{
			return (0);
		}
	}

	return (1);
}
