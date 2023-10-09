#include "main.h"

/**
 * _exit_num - Exits the Shell with an integer 'exit <N0>'
 * @local_argv: The string to be converted into an integer.
 */
void _exit_num(_dou_p local_argv)
{
	int x;

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

		int _no = _atoi(local_argv[1]);

		exit(_no);
	}
	exit(1);
}
