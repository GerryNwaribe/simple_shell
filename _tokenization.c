#include "main.h"

/**
 * _tokenization - Takes the string from stdin and tokenize into dou_p
 * @gtln: The string to be tokenized.
 * @_delimiters: The string of delimiters for parsing.
 * Return: A Double pointer.
 *
 */
dou_p _tokenization(string gtln, string _delimiters)
{
	string token;
	int i = 0, _idx = 0;
	dou_p local_argv;

	i = 0;
	while (gtln[_idx] != '\0')
	{
		if (strchr(_delimiters, gtln[_idx]))
			i++;
		_idx++;
	}
		local_argv = malloc(sizeof(char *) * (i + 2));

	token = strtok(gtln, _delimiters);

	_idx = 0;
	while (token != NULL)
	{
		local_argv[_idx] = token;
		_idx++;
		token = strtok(NULL, _delimiters);
	}
	local_argv[_idx] = NULL;

	if (local_argv == NULL)
		_free(local_argv, 1);

	return (local_argv);
}
