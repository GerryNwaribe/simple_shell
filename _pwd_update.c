#include "main.h"

/**
 * _pwd_update - updats the pwd and oldpwd
 * @__s: either the PWD or OLDPWD
 * Return: void.
 */
void _pwd_update(char __s[])
{
	char new_var[_BFFSZ], _s[_BFFSZ];
	char **env = environ;
	int dx = 0;

	getcwd(_s, sizeof(_s));

	strcpy(new_var, __s);
	strcat(new_var, "=");
	strcat(new_var, _s);
	for (; *env; dx++, env++)
	{
		if (!(strncmp(__s, *env, strlen(__s)))) /* Replace existing variable */
			strcpy(environ[dx], new_var);
	}
}
