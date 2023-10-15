#include "main.h"

/**
 * main - Simple Shell main function.
 * @argv: double pointer for strings on stdin.
 * @_cxt: stdin word count.
 * @env: Environmental variable.
 * Return: returns 0 on success.
 */
int main(int _cxt, dou_p argv, dou_p env)
{
	size_t bffsz = 0, line_num = 1;
	string getline_bffr;
	dou_p dou_argv, semi_colon;

	(void)_cxt;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_print_string("[x] ");

		if ((getline(&getline_bffr, &bffsz, /*STDIN_FILENO*/ stdin) == EOF))
		{
			_putchar('\n'); /* ctrl D */
			exit(-1);
		}
		if (!(strcmp(getline_bffr, "\n"))) /* Handles New line */
		{
			line_num++;
			continue;
		}

		semi_colon = _tokenization(getline_bffr, ";|&"); /* Works fine for ';', not so well for '&&' and '||' */

		for (; *semi_colon; semi_colon++)
		{
			dou_argv = _tokenization(*semi_colon, " \n\t\r");

			if (dou_argv && (!(_is_prsent(dou_argv[0]))))
			{
				_slt(dou_argv[0])(dou_argv, line_num, argv);
				continue;
			}

			_execmd(dou_argv, env, argv, line_num);
		}

		free(dou_argv);
		if (isatty(STDIN_FILENO) == 0)
			break;
	}
	free(getline_bffr);
	return (0);
}
