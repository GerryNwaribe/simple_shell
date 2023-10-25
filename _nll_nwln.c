#include "main.h"

/**
 * _nll_nwln - NULLs the new line char in gtln
 * @gtln: The string to be NULLED
 * @read: Total length of chars in gtln
 * Return: a pointer to nulled string
 */
string _nll_nwln(string gtln, ssize_t read)
{
	if (_isblnk(gtln))     /* if what's in gtln is "\n\0" OR whitespaces */
	{
		return (NULL);
	}

	if ((read != EOF) && (gtln[read - 1] == '\n'))
	{
		gtln[read - 1] = '\0';
		return (gtln);
	}

	return (gtln);
}
