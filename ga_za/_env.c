#include "main.h"

/**
 * _env - This function prints all environmental variables.
 * Void input and output.
 */
int _env(_dou_p cmmd)
{
	_dou_p dx;

	(void)cmmd;

	for (dx = environ; *dx; dx++)
	{
		_print_string(*dx);
		_putchar('\n');
	}
	return (0);
}
