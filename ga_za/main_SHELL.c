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
	_dou_p local_argv;

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

		local_argv = _tokenization(getline_bffr, " \n\t\r");

		if (local_argv && !(_strcmp(local_argv[0], "cd")))
		{
			_cd(local_argv);			
			continue;
		}

		if (local_argv && !(_strcmp(local_argv[0], "env")))
		{
			_env();
			continue;
		}
		if (local_argv && !(_strcmp(local_argv[0], "exit")))
			_exit_num(local_argv);

		execmd(local_argv, env, argv);

		free(local_argv);
		if (isatty(STDIN_FILENO) == 0)
			break;
	}
	free(getline_bffr);
	return (0);
}
