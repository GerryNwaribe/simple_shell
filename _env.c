#include "main.h"

/**
 * _env - This function prints all environmental variables.
 * Void input and output.
 * @cmmd: command
 * @line_num: line number
 * @argv: argument vector
 * Return: 0
 */
int _env(dou_p cmmd, size_t line_num, dou_p argv, dou_p first_cmm)
{
	dou_p dx = environ;

	(void)cmmd;
	(void)argv;
	(void)line_num;
	_free(first_cmm, 0);

	for (; *dx; dx++)
	{
		_print_string(*dx);
		_putchar('\n');
	}
	return (0);
}
