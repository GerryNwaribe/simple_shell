#include "main.h"

/**
 * _execmd - Handles the exec of valid PATH.
 * @dou_cm: Tokenized string gotten from stdin.
 * @ft_cmm: Tokenized string gotten from dou_cm.
 * @env: Environmental variables.
 * @av: Command line argument.
 * @ln_nu: line number
 * Return: void
 */
void _execmd(dou_p dou_cm, dou_p env, dou_p av, size_t ln_nu, dou_p ft_cmm);
void _execmd(dou_p dou_cm, dou_p env, dou_p av, size_t ln_nu, dou_p ft_cmm)
{
	int _exev_Rv, _status;
	pid_t _child_PID_Rv;
	string _addr = NULL;

	(void)env, (void)ln_nu;
	if (dou_cm)
	{
		_addr = _get_PATH(dou_cm[0]);
		if (_addr == NULL)
		{
			_free(_addr, 0);
			_free(ft_cmm, 0);
			_error_MESSAGE(av, ln_nu, dou_cm, "addr");
			exit(127);
		}
		_child_PID_Rv = fork();
		if (_child_PID_Rv < 0)
		{
			perror(av[0]);
			if (dou_cm != NULL)
			{
				_free(_addr, 0);
				_free(dou_cm, 0);
				exit(EXIT_FAILURE);
			}
		}
		else if (_child_PID_Rv == 0)
		{
			_exev_Rv = execve(_addr, dou_cm, environ);
			if (_exev_Rv == ERROR)
			{
				perror("av[0] [Execve]");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&_status);
	}
	_free(_addr, 0);
}
