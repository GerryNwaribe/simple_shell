#include "main.h"

/**
 * _tokenize_slt_exec - Tokenize, parse, execute shell commands ';' and '||'
 * @gtln: The input string to be tokenized and executed
 * @env: An array of environment variables.
 * @av: An array of command-line arguments.
 * @l_dx: The current line number for error reporting.
 * Return: 0 on success, -1 on failure.
 */

int _tokenize_slt_exec(string gtln, dou_p env, dou_p av, size_t l_dx)
{
	dou_p dou_cmm = NULL, first_cmm = NULL;
	int i = 0;

	first_cmm = _tokenization(gtln, "\n");

	for (i = 0; first_cmm[i]; i++)
	{
		dou_cmm = _tokenization(first_cmm[i], " \n");

		if (!dou_cmm[0])
		{
			_free(dou_cmm, 0);
			return (0);
		}

		if (dou_cmm[0] && (!(_is_prsent(dou_cmm[0]))))
		{
			_slt(dou_cmm[0])(dou_cmm, l_dx, av);
			/*_free(dou_cmm, 0);*/
		}
		if (dou_cmm[0])
		{
			_execmd(dou_cmm, env, av, l_dx);
		}
	}
		_free(first_cmm, 0);
		_free(dou_cmm, 0);
	return (0);
}
