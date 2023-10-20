#include "main.h"

/**
 * _execmd - Handles the exec of valid PATH.
 * @dou_cmmd: Tokenized string gotten from stdin.
 * @env: Environmental variables.
 * @argv: Command line argument.
 * @line_num: line number
 * Return: void
 */
void _execmd(dou_p dou_cmmd, dou_p env, dou_p argv, size_t line_num, dou_p first_cmm);
void _execmd(dou_p dou_cmmd, dou_p env, dou_p argv, size_t line_num, dou_p first_cmm)
{
	int _exev_Rv, _status;
	pid_t _child_PID_Rv;
	string _addr = NULL;

	(void)env, (void)line_num;
	if (dou_cmmd)
	{
		_addr = _get_PATH(dou_cmmd[0]);
		printf("%s\n", _addr);

		if (_addr == NULL)
		{
			_free(_addr, 0);
			_free(first_cmm, 0);
			_error_MESSAGE(argv, line_num, dou_cmmd, "addr");
			exit(127);
		}
		_child_PID_Rv = fork();
		if (_child_PID_Rv < 0)
		{
			perror(argv[0]);
			if (dou_cmmd != NULL)
			{
				_free(_addr, 0);
				_free(dou_cmmd, 0);
				exit(EXIT_FAILURE);
			}
		}
		else if (_child_PID_Rv == 0)
		{
			_exev_Rv = execve(_addr, dou_cmmd, environ);
			if (_exev_Rv == ERROR)
			{
				perror("argv[0] [Execve]");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&_status);
	}
	_free(_addr, 0);
}
