#include "main.h"

/**
 * _exit_num - Exits the Shell with an integer 'exit <N0>'
 * @local_argv: The string to be converted into an integer.
 */
int _exit_num(_dou_p local_argv)
{
	int x, _no;

	if (local_argv[1])
	{
		for (x = 0; local_argv[1][x]; x++)
		{
			if (_isdigit(local_argv[1][x]))
			{
				continue;
			}
			else
				exit(-1);
		}

		_no = _atoi(local_argv[1]);

		exit(_no);
	}
	exit(1);
}
