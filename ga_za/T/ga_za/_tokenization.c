#include "main.h"

/**
 * _tokenization - Takes the string from stdin and tokenize into _dou_p
 * @str: The string to be tokenized.
 * @_delimiters: The string of delimiters for parsing.
 * Return: A Double pointer.
 *
 */
_dou_p _tokenization(string str, string _delimiters)
{

	string token;
	int i = 0, idx = 0;
	_dou_p local_argv = NULL;
	/*char *local_argv[_BFFSZ];*/

	i = 0;
	while (str[idx] != '\0')
	{
		if (_strchr(_delimiters, str[idx]))
			i++;
		idx++;
	}

	local_argv = malloc(sizeof(char *) * (i + 1));

	token = _strtok(str, _delimiters);

	idx = 0;
	while (token != NULL)
	{
		local_argv[idx] = token;
		idx++;
		token = _strtok(NULL, _delimiters);
	}
	local_argv[idx] = NULL;

	return (local_argv);
}
