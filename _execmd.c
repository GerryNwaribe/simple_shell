#include "main.h"

/**
 * _execmd - Handles the exec of valid PATH.
 * @local_argv: Tokenized string gotten from stdin.
 * @env: Environmental variables.
 * @argv: Command line argument.
 * @line_num: line number
 * Return: void
 */
void _execmd(dou_p local_argv, dou_p env, dou_p argv, size_t line_num)
{
	int _exev_Rv, _status;
	pid_t _child_PID_Rv;
	string atl_cmmd = NULL;

	if (local_argv)
	{
		atl_cmmd = _get_PATH(local_argv[0]);
		if (atl_cmmd == NULL)
		{
			_print_string(argv[0]);
			_print_string(": ");
			_print_num(line_num, 0);
			_print_string(": ");
			_print_string(local_argv[0]);		/*sh: 3: exi: not found*/
			_print_string(": not found");
			_putchar('\n');
			return;
		}
		_child_PID_Rv = fork();
		if (_child_PID_Rv < 0)
		{
			perror(argv[0]);
			if (local_argv != NULL)
			{
				_free(local_argv, 1);
				exit(EXIT_FAILURE);
			}
		}
		else if (_child_PID_Rv == 0)
		{
			_exev_Rv = execve(atl_cmmd, local_argv, NULL);
			if (_exev_Rv == ERROR)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&_status);
	}
}
