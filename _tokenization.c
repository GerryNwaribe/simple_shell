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
	string token = NULL, _stck_arr[_BFFSZ];
	dou_p dou_cmm;
	int _idx = 0;

	token = strtok(gtln, _delimiters);

	for (_idx = 0; token != NULL; _idx++, token = strtok(NULL, _delimiters))
		_stck_arr[_idx] = token;

	_stck_arr[_idx] = NULL;

	dou_cmm = malloc(sizeof(char *) * (_idx + 1));
	if (dou_cmm == NULL)
	{
		_free(dou_cmm, 0);
		return (NULL);
	}

	for (_idx = 0; _stck_arr[_idx] != NULL; _idx++)
		dou_cmm[_idx] = strdup(_stck_arr[_idx]);

	dou_cmm[_idx] = NULL;

	return (dou_cmm);
}
