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
		if ((read == EOF && !(isatty(STDIN_FILENO))) || (read == EOF && (isatty(STDIN_FILENO))))
		{
			_free(gtln, 0);
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			exit(0);
		}

		gtln[strcspn(gtln, "\n")] = '\0';

		if ((!(isatty(STDIN_FILENO)) && read == EOF) && _isblnk(gtln)) /*  21th oct 6am  */ /* 21 oct 11 59pm */
		{
			_free(gtln, 0);
			break;
		}

		if (gtln == NULL || _isblnk(gtln))
		{
			line_num++;
			continue;
		}

		_tokenize_slt_exec(gtln, env, argv, line_num);

	}

	return (0);
}
