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
	size_t bffsz = 0, ln_cnt = 1;
	string gtln = NULL, _gtln = NULL;
	ssize_t read;

	(void)_cxt, (void)_head_;
	while (GERRY)
	{
		if (isatty(STDIN_FILENO))
			_print_string(" .:[$) ");
		read = getline(&gtln, &bffsz, stdin);
		if ((read == EOF && !(isatty(STDIN_FILENO))) ||
			(read == EOF && (isatty(STDIN_FILENO))))
		{
			_free(gtln, 0);
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			exit(0);
		}
		_gtln = _nll_nwln(gtln, read); /* frees gtln and set "\n" to NULL in new buffer */
		if ((!(isatty(STDIN_FILENO)) && read == EOF) && _isblnk(gtln))
		{
			_free(_gtln, 0);
			break;
		}
		if (_gtln == NULL || _isblnk(_gtln))
		{
			ln_cnt++;
			continue;
		}
		_tokenize_slt_exec(_gtln, env, argv, ln_cnt);
	}
	return (0);
}
