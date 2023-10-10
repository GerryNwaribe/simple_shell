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
	_dou_p dou_vctr;

	(void)_cxt;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_print_string("[$] ");
		if ((getline(&getline_bffr, &bffsz, stdin)) == EOF)
		{
			_putchar('\n');
			exit(-1);
		}
		if (!(strcmp(getline_bffr, "\n")))
			continue;

		dou_vctr = _tokenization(getline_bffr, " \n\t\r");

		if (dou_vctr && !(_strcmp(dou_vctr[0], "cd")))
		{
			_cd(dou_vctr);			
			continue;
		}

		if (dou_vctr && !(_strcmp(dou_vctr[0], "env")))
		{
			_env();
			continue;
		}
		if (dou_vctr && !(_strcmp(dou_vctr[0], "exit")))
			_exit_num(dou_vctr);

		execmd(dou_vctr, env, argv);

		free(dou_vctr);
		if (isatty(STDIN_FILENO) == 0)
			break;
	}
	free(getline_bffr);
	return (0);
}
