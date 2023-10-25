#include "main.h"

/**
 * _exit_num - Exits the Shell with an integer 'exit <N0>'
 * @dou_cmm: The string to be converted into an integer.
 * @line_num: line number
 * @argv: argument vector
 * Return: exit number
 */
int _exit_num(dou_p dou_cmm, size_t line_num, dou_p argv, dou_p first_cmm)
{
	int x, _no;

	(void)argv, (void)line_num;
	_free(first_cmm, 0);

	if (dou_cmm[1])
	{
		for (x = 0; dou_cmm[1][x]; x++)
		{
			if (_isdigit(dou_cmm[1][x]))
			{
				continue;
			}
			else
			{
				_free(dou_cmm, 1);
				exit(0);
			}
		}

		_no = _atoi(dou_cmm[1]);
		_free(dou_cmm, 1);
		exit(_no);
	}

	_free(dou_cmm, 1);
	exit(0);
}
