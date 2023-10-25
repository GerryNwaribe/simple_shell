#include "main.h"

/**
 * _slt - Loops & compares 's' with the struct 'key_w'
 * @s: The string to be compared with 'key_w'
 * Return: A function pointer if found, otherwise returns 0
 */
int (*_slt(string s))(dou_p dou_av, size_t ln_nm, dou_p av, dou_p _cmm)
{
	int x;

	_is fmt[] = {
		{"cd", &_cd},
		{"env", &_env},
		{"alias", &_alias},
		{"exit", &_exit_num},
		{"setenv", &_setenv},
		{"unsetenv", &_unsetenv},
		{'\0', NULL},
	};

	for (x = 0; fmt[x].key_w; x++)
	{
		if (!(strcmp(s, fmt[x].key_w)))
			return (fmt[x]._func);
	}

	return (0);
}
