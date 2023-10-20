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
	dou_p dou_cmm = NULL, first_cmm = NULL;
	int x;

	first_cmm = _tokenization(gtln, ";\n|&");

	if (first_cmm == NULL)
		return (0);

	for (x = 0; first_cmm[x]; x++)
	{
		dou_cmm = _tokenization(first_cmm[x], " \n");

		if (!dou_cmm[0])
		{
			_free(dou_cmm, 0);
			return (0);
		}

		if (dou_cmm[0] && (!(_is_prsent(dou_cmm[0]))))
		{
			if (!strcmp(dou_cmm[0], "exit"))
				_free(first_cmm, 0);

			_slt(dou_cmm[0])(dou_cmm, ln_cnt, av);
		}
		else
		{
			_execmd(dou_cmm, env, av, ln_cnt, first_cmm);
		}
	}
		_free(first_cmm, 0);
		_free(dou_cmm, 0);
	return (0);
}
