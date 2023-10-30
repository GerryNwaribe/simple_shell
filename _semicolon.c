#include "main.h"

/**
 * _semicolon - Handles the when there semicolon in the input
 * @gtln: string with semicolon present
 * @env: environmental varibles
 * @ln_cnt: line number
 * @av: argument vector
 * Return: integer successs or failure
 */
int _semicolon(string gtln, dou_p env, dou_p av, size_t ln_cnt)
{
	dou_p dou_cmm = NULL, split_cmm = NULL;
	int x;

	(void)_head_;
	split_cmm = _tokenization(gtln, ";");
	if (split_cmm == NULL)
		return (ERROR);

	for (x = 0; split_cmm[x] != NULL; x++)
	{
		if (strstr(split_cmm[x], "exit"))
			_exit_num(dou_cmm, ln_cnt, av, split_cmm);

		_tokenize_slt_exec(split_cmm[x], env, av, ln_cnt);
	}

	_free(split_cmm, 1);
	return (0);
}
