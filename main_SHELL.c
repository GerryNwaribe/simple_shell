#include "main.h"

/**
 * main - Simple Shell main function.
 * @argv: double pointer for strings on stdin.
 * @_cxt: stdin word count.
 * @env: Environmental variable.
 * Return: returns 0 on success.
 */
int main(int _cxt, dou_p argv, dou_p env)
{
	size_t bffsz = 0, line_num = 1;
	string getline_ptr;
	/*dou_p dou_argv, semi_colon;*/

	(void)_cxt;
	while (GERRY)
	{
		if (isatty(STDIN_FILENO)) 
			_print_string(".:[x) ");

		if ((_getline(&getline_ptr, &bffsz, STDIN_FILENO) == EOF))	/* ctrl D */
		{
			_putchar('\n');
			exit(ERROR);
		}
		
		if (!(_strcmp(getline_ptr, "\n"))) /* Handles New line */
		{
			line_num++;
			continue;
		}

		_tokenize_slt_exec(getline_ptr, env, argv, line_num);

		/*semi_colon = _tokenization(getline_ptr, ";|&"); 			 works fine for ';', not so well for '&&' and '||'

		

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
*/
		if (!(isatty(STDIN_FILENO)))
			break;
	}
	/*free(getline_ptr);*/
	return (0);
}