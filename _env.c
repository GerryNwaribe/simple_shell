#include "main.h"

/**
 * _env - This function prints all environmental variables.
 * Void input and output.
 * @cmmd: command
 * @line_num: line number
 * @argv: argument vector
 * @splt_cmm: dou command in splits.
 * Return: 0
 */
int _env(dou_p cmmd, size_t line_num, dou_p argv, dou_p splt_cmm)
{
	dou_p dx = environ;

	(void)cmmd;
	(void)argv;
	(void)line_num;
	(void)_head_;
	_free(splt_cmm, 0);

	for (; *dx; dx++)
	{
		_print_string(*dx);
		_putchar('\n');
	}
	return (0);
}
