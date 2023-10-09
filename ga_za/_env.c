#include "main.h"

/**
 * _env - This function prints all environmental variables.
 * Void input and output.
 */
void _env(void)
{
	_dou_p dx;

	for (dx = environ; *dx; dx++)
	{
		_print_string(*dx);
		_putchar('\n');
	}
}
