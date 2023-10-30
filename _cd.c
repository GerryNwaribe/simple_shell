#include "main.h"

/**
 * _cd - This function.
 * @cmmd: The command from stdin who's path is to be found.
 * @line_num: line number
 * @argv: argument vector
 * @splt_cmm: dou command in splits.
 * Return: void.
 */
int _cd(dou_p cmmd, size_t line_num, dou_p argv, dou_p splt_cmm)
{
	const char *hm = getenv("HOME");
	char _old[] = "OLDPWD", _new[] = "PWD", _old_[_BFFSZ];

	(void)splt_cmm, (void)_head_;
	if (cmmd[1])
	{
		if (!(strcmp(cmmd[1], "-")))
		{
			strcpy(_old_, (getenv("OLDPWD")));
			_pwd_update(_old);
			if (chdir(_old_))
				perror("[OLDPWD Not set]");
			_pwd_update(_new);
			return (0);
		}
		if (!(access(cmmd[1], X_OK)))
		{
			_pwd_update(_old);
			if (chdir(cmmd[1]))
				_error_MESSAGE(argv, line_num, cmmd, "cd");
			_pwd_update(_new);
			return (0);
		}
	}
	else
	{
		_pwd_update(_old);
		if (chdir(hm))
			perror("[HOME Not set]");
		_pwd_update(_new);
		return (0);
	}
	return (1);
}
