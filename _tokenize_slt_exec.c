#include "main.h"

/**
 * _tokenize_slt_exec - Tokenize, parse, execute shell commands ';'
 * @gtln: The input string to be tokenized and executed
 * @env: An array of environment variables.
 * @av: An array of command-line arguments.
 * @ln_cnt: The current line number for error reporting.
 * Return: 0 on success, -1 on failure.
 */
int _tokenize_slt_exec(string gtln, dou_p env, dou_p av, size_t ln_cnt)
{
	dou_p dou_cmm = NULL, alx = NULL;

	if (_is_semicolon(gtln))
	{
		_semicolon(gtln, env, av, ln_cnt);
		return (EXIT_SUCCESS);
	}

	dou_cmm = _tokenization(gtln, " \n");
	if (!dou_cmm[0])
	{
		_free(dou_cmm, 1);
		return (ERROR);
	}

	if (dou_cmm[0] && (!(_is_prsent(dou_cmm[0]))))
	{
		_slt(dou_cmm[0])(dou_cmm, ln_cnt, av, alx);
	}
	else
		_execmd(dou_cmm, env, av, ln_cnt, (dou_p)gtln);

	_free(dou_cmm, 1);
	return (0);
}
