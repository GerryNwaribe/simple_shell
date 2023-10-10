#include "main.h"

/**
 * _slt -
 * @s:
 * Return:
 */
int (*_slt(string s))(_dou_p dou_argv)
{
	int x;

	_is fmt[] = {
		{"cd", &_cd},
		{"env", &_env},
		{"exit", &_exit_num},
		{'\0', NULL},
	};

	for (x = 0; fmt[x].key_w; x++)
	{
		if (!(_strcmp(s, fmt[x].key_w)))
			return (fmt[x]._func);
	}
	return (0);
}
