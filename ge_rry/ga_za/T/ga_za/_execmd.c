#include "main.h"

/**
 * execmd - Handles the exec of valid PATH.
 * @local_argv: Tokenized string gotten from stdin.
 * @env: Environmental variables.
 * @argv: Command line argument.
 *
 */
void execmd(_dou_p local_argv, _dou_p env, _dou_p argv)
{
	int _exev_Rv, _status;
	pid_t _child_PID_Rv;
	string atl_cmmd = NULL;

	(void)env;
	if (local_argv)
	{
		atl_cmmd = get_PATH(local_argv[0]);
		if (atl_cmmd == NULL)
		{
			perror(argv[0]);
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
			_exev_Rv = execve(atl_cmmd, local_argv, env);
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
