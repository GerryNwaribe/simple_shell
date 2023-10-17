#include "main.h"

/**
 * execmd - Handles the exec of valid PATH.
 * @local_argv: Tokenized string gotten from stdin.
 * @env: Environmental variables.
 * @argv: Command line argument.
 *
 */
int _execmd_return_value = 0; // Global variable to store the return value of _exev_Rv

void _execmd(dou_p local_argv, dou_p env, dou_p argv, size_t line_num)
{
    int _exev_Rv, _status;
    pid_t _child_PID_Rv;
    string atl_cmmd = NULL;

    /*(void)env;*/
    if (local_argv)
    {
        atl_cmmd = _get_PATH(local_argv[0]);

        if (atl_cmmd == NULL)
        {                                       
            _print_string(argv[0]);
            _print_string(": ");
            _print_num(line_num, 0);
            _print_string(": ");
            _print_string(local_argv[0]);       /*sh: 3: exi: not found*/
            _print_string(": not found");
            _putchar('\n');
            return;
        }

        _child_PID_Rv = fork();
        if (_child_PID_Rv < 0)
        {
            perror(argv[0]);
            if (local_argv != NULL)         /*ls: cannot access '11': No such file or directory*/
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

    _execmd_return_value = _exev_Rv; // Store the return value in the global variable
}
/*void _execmd(dou_p local_argv, dou_p env, dou_p argv, size_t line_num)
{
	int _exev_Rv, _status;
	pid_t _child_PID_Rv;
	string atl_cmmd = NULL;

	(void)env;
	if (local_argv)
	{
		atl_cmmd = _get_PATH(local_argv[0]);

		if (atl_cmmd == NULL)
		{										
			_print_string(argv[0]);
			_print_string(": ");
			_print_num(line_num, 0);
			_print_string(": ");
			_print_string(local_argv[0]);	sh: 3: exi: not found
			_print_string(": not found");
			_putchar('\n');
			return;
		}

		_child_PID_Rv = fork();
		if (_child_PID_Rv < 0)
		{
			perror(argv[0]);
			if (local_argv != NULL)			ls: cannot access '11': No such file or directory
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
}*/

