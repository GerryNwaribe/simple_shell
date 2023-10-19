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
	dou_p /*dou_cmm = NULL,*/ mult_cmm = NULL;
	int x = 0;

	mult_cmm = _tokenization(gtln, " ");

	for (x = 0; mult_cmm[x]; x++)
	{
		/*dou_cmm = _tokenization(mult_cmm[x], " \n\t\r");*/

		/*for (; dou_cmm[x]; x++)
			printf("%s\n", dou_cmm[x]);*/

		if (!mult_cmm[0])
		{
			_free(mult_cmm, 0);
			return (0);
		}

		if (mult_cmm[0] && (!(_is_prsent(mult_cmm[0]))))
		{
			_slt(mult_cmm[0])(mult_cmm, l_dx, av);
			_free(mult_cmm, 0);
			return (0);
		}
		if (mult_cmm[0])
		{
			_execmd(mult_cmm, env, av, l_dx);
			return (0);
		}

		if (mult_cmm[0] != NULL)
			_free(mult_cmm, 0);
	}

	return (0);
}

/*
int _tokenize_slt_exec(string gtln, dou_p env, dou_p av, size_t l_dx)
{
	dou_p dou_cmm = NULL;
	int x = 0;

	dou_cmm = _tokenization(gtln, " \n\t\r");

	for (; dou_cmm[x]; x++)
		printf("%s\n", dou_cmm[x]);

	if (!dou_cmm[0])
	{
		_free(dou_cmm, 0);
		return (0);
	}

	if (dou_cmm[0] && (!(_is_prsent(dou_cmm[0]))))
	{
		_slt(dou_cmm[0])(dou_cmm, l_dx, av);
		_free(dou_cmm, 0);
		return (0);
	}
	if (dou_cmm[0])
	{
		_execmd(dou_cmm, env, av, l_dx);
		return (0);
	}

	if (dou_cmm[0] != NULL)
		_free(dou_cmm, 0);


	return (0);
}
*/
