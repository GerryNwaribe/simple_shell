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
	string token = NULL, _stckarr[_BFFSZ];
	dou_p dou_cmm;
	int _idx = 0;

	token = strtok(gtln, _delimiters);

	for (_idx = 0; token != NULL; _idx++, token = strtok(NULL, _delimiters))
		_stckarr[_idx] = token;

	_stckarr[_idx] = NULL;

	dou_cmm = malloc(sizeof(char *) * (_idx + 1));

	for (_idx = 0; _stckarr[_idx] != NULL; _idx++)
		dou_cmm[_idx] = _stckarr[_idx];

	dou_cmm[_idx] = NULL;


	if (dou_cmm == NULL)
	{
		_free(dou_cmm, 0);
		return (NULL);
	}

	return (dou_cmm);
}
