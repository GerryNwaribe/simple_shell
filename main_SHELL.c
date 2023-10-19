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
	ssize_t read;

	(void)_cxt;
	while (GERRY)
	{
		if (isatty(STDIN_FILENO))
			_print_string(" .:[:) ");

		read = getline(&gtln, &bffsz, stdin);
		if (read == EOF && isatty(STDIN_FILENO))
		{
			_free(gtln, 0);
			_putchar('\n');
			exit(ERROR);
		}
		if (!(isatty(STDIN_FILENO)) && read == EOF)
			break;
		if (gtln[read - 1] == '\n')
			gtln[read - 1] = '\0';

		if (gtln == NULL)
		{
			line_num++;
			continue;
		}

		_tokenize_slt_exec(gtln, env, argv, line_num);

	}

	return (0);
}
