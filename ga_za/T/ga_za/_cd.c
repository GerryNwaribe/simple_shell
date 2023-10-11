#include "main.h"

/**
 * _cd - This function.
 * @cmmd: The command from stdin who's path is to be found.
 * Return: void.
 */
int _cd(_dou_p cmmd)
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
		else
			perror("cd");

		if ((chdir(cmmd[1])))
			perror("cd");
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
