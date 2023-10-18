#include "main.h"

/**
 * _tokenize_slt_exec - Tokenize, parse, execute shell commands ';' and '||'
 * @getline_bffr: The input string to be tokenized and executed
 * @env: An array of environment variables.
 * @argv: An array of command-line arguments.
 * @line_num: The current line number for error reporting.
 * Return: 0 on success, -1 on failure.
 */
int _tokenize_slt_exec(string getline_bffr, dou_p env, dou_p argv, size_t line_num)
{
	dou_p dou_argv, semi_colon;
	

	semi_colon = _tokenization(getline_bffr, ";"); /* Works fine for ';', not so well for '&&' and '||'*/

	for (; *semi_colon; semi_colon++)
	{
		

	
			dou_argv = _tokenization(*semi_colon, " \n\t\r");

			if (dou_argv && (!(_is_prsent(dou_argv[0]))))
			{
				_slt(dou_argv[0])(dou_argv, line_num, argv);
				continue;
			}

			_execmd(dou_argv, env, argv, line_num);
			
		
	}
	free(dou_argv);
	return (0);
}
