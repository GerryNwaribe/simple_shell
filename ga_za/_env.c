#include "main.h"

/**
 * _env - This function prints all environmental variables.
 * Void input and output.
 */
int _env(_dou_p cmmd, size_t line_num, _dou_p argv)
{
	_dou_p dx;

	(void)cmmd;
	(void)argv;
	(void)line_num;

	for (dx = environ; *dx; dx++)
	{
		_print_string(*dx);
		_putchar('\n');
	}
	return (0);
}
