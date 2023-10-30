#include "main.h"

/**
 * _pwd_update - updats the pwd and oldpwd
 * @__s: either the PWD or OLDPWD
 * Return: void.
 */
void _pwd_update(char __s[])
{
	char _v[_BFFSZ];
	char *dou_cmm[3];


	(void)_head_;
	getcwd(_v, sizeof(_v));

	dou_cmm[0] = "setenv";
	dou_cmm[1] = __s;
	dou_cmm[2] = _v;
	dou_cmm[3] = NULL;

	_setenv(dou_cmm, 0, NULL, NULL);


}
