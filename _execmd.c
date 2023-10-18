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
	string _addr = NULL;
	/*char _addr_cp[_BFFSZ];
	char *_cmmd_PTR[_BFFSZ];*/

	if (local_argv)
	{
		_addr = _get_PATH(local_argv[0]);
		/*strcpy(_addr_cp, _addr);
		_free(_addr, 0);*/

		if (_addr == NULL)
		{
			_error_MESSAGE(argv, line_num, local_argv, "addr");
			return;
		}
		_child_PID_Rv = fork();
		if (_child_PID_Rv < 0)
		{
			perror(argv[0]);
			if (local_argv != NULL)
			{
				_free(local_argv, 0);
				exit(EXIT_FAILURE);
			}
		}
		else if (_child_PID_Rv == 0)
		{
			_exev_Rv = execve(_addr, local_argv, NULL);

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
	_free(local_argv, 0);
}
