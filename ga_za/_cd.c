#include "main.h"

/**
 * _cd - This function.
 * @cmmd: The command from stdin who's path is to be found.
 * Return: void.
 */
int _cd(_dou_p cmmd, size_t line_num, _dou_p argv)
{
	const char *hm = _getenv("HOME");
	const char *p_wd = _getenv("OLDPWD");

	if (cmmd[1])
	{
		if (p_wd)
		{
			if (!(_strcmp(cmmd[1], "-")))
			{
				if (chdir(p_wd))
					perror("cd");
				return (0);
			}
		}
		/*else
			perror("cd");*/

		if ((chdir(cmmd[1])))
		{
			_print_string(argv[0]);
			_print_string(": ");
			_print_num(line_num, 0);
			_print_string(": ");
			_print_string(cmmd[0]);		/* sh: 3: cd: can't cd to g */
			_print_string(": can't cd to ");
			_print_string(cmmd[1]);
			_putchar('\n');
		}
			

		return (0);
	}
	else
	{
		if (hm)
		{
			if (chdir(hm))
				perror("cd");
			return (0);
		}
		else
			perror("cd");
	}
	return (1);
}
