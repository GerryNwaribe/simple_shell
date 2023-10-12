#include "main.h"

/**
 * main - Simple Shell main function.
 * @argv: double pointer for strings on stdin.
 * @_cxt: stdin word count.
 * @env: Environmental variable.
 * Return: returns 0 on success.
 */
int main(int _cxt, _dou_p argv, _dou_p env)
{
	size_t bffsz = 0;
	string getline_bffr;
	_dou_p dou_argv;

	(void)_cxt;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_print_string("[$] ");
		
		if ((_getline(&getline_bffr, &bffsz, STDIN_FILENO/* stdin */) == EOF))
		{
			_putchar('\n');
			exit(-1);
		}


		if (!(strcmp(getline_bffr, "\n")))
			continue;

		dou_argv = _tokenization(getline_bffr, " \n\t\r");

		if (dou_argv && (!(_is_prsent(dou_argv[0]))))
		{
			_slt(dou_argv[0])(dou_argv);
			continue;
		}

		execmd(dou_argv, env, argv);

		free(dou_argv);
		if (isatty(STDIN_FILENO) == 0)
			break;
	}
	free(getline_bffr);
	return (0);
}
