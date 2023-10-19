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
	string gtln = NULL;
	/*dou_p dou_argv, semi_colon;*/
	ssize_t read = 0;

	(void)_cxt;
	while (GERRY)
	{
		if (isatty(STDIN_FILENO))
			_print_string(" .:[:) ");

		read = getline(&gtln, &bffsz, stdin);
		if (!(isatty(STDIN_FILENO)) && read == EOF)
			break;
		if (read == EOF)
		{
			_free(gtln, 0);
			_putchar('\n');
			exit(ERROR);
		}

		if (!(strcmp(gtln, "\n"))) 
		{
			line_num++;
			continue;
		}




		_tokenize_slt_exec(gtln, env, argv, line_num);


	}
	return (0);
}
