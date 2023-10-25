#include "main.h"

/**
 * _cd - This function.
 * @cmmd: The command from stdin who's path is to be found.
 * @line_num: line number
 * @argv: argument vector
 * Return: void.
 */
int _cd(dou_p cmmd, size_t line_num, dou_p argv, dou_p splt_cmm)
{
	const char *hm = getenv("HOME");
	char p_wd[_BFFSZ];
	char _old[] = "OLDPWD", _new[] = "PWD";

	(void)splt_cmm;
	if (cmmd[1])
	{
		if (!(strcmp(cmmd[1], "-")))
		{
			strcpy(p_wd, getenv("OLDPWD"));
			_pwd_update(_old);
			if (chdir(p_wd))
				perror("cd [OLDPWD Not set]");
			_pwd_update(_new);
			return (0);
		}
		_pwd_update(_old);
		if (chdir(cmmd[1]))
			_error_MESSAGE(argv, line_num, cmmd, "cd");
		_pwd_update(_new);
		return (0);
	}
	else
	{
		_pwd_update(_old);
		if (chdir(hm))
			perror("cd [HOME Not set]");
		_pwd_update(_new);
		return (0);
	}
	return (1);
}
