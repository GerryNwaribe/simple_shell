#include "main.h"

/**
 * _execmd - Handles the exec of valid PATH.
 * @dou_cmmd: Tokenized string gotten from stdin.
 * @env: Environmental variables.
 * @argv: Command line argument.
 * @line_num: line number
 * Return: void
 */
void _execmd(dou_p dou_cmmd, dou_p env, dou_p argv, size_t line_num)
{
	int _exev_Rv, _status;
	pid_t _child_PID_Rv;
	string _addr = NULL;
	/* char *_cp_cmm[_BFFSZ]; */

	(void)env;
	if (dou_cmmd)
	{
		_addr = _get_PATH(dou_cmmd[0]);
		if (_addr == NULL)
		{
			_error_MESSAGE(argv, line_num, dou_cmmd, "addr");
			_free(dou_cmmd, 0);
			return;
		}
		_child_PID_Rv = fork();
		if (_child_PID_Rv < 0)
		{
			perror(argv[0]);
			if (dou_cmmd != NULL)
			{
				_free(dou_cmmd, 0);
				exit(EXIT_FAILURE);
			}
		}
		else if (_child_PID_Rv == 0)
		{
			_exev_Rv = execve(_addr, dou_cmmd, environ);

			if (_exev_Rv == ERROR)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&_status);
	}
	_free(_addr, 0);
	/*_free(dou_cmmd, 0);*/
}
