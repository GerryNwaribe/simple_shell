#include "main.h"

/**
 * get_PATH - This function gets all PATHs
 *                          and determine the path for the command.
 * @cmmd: The command from stdin who's path is to be found.
 * Return: A pointer to valid PAth or NULL if it doesn't exist.
 */
string _get_PATH(string cmmd)
{
	int dir_length, cmmd_length = strlen(cmmd);
	string path = NULL, _token = NULL, _addr = NULL, _cmmd = NULL;
	char path_cp[_BFFSZ], file_path[_BFFSZ];
	struct stat bffr;

	path = getenv("PATH");

	if (!(stat(cmmd, &bffr)) && !(access(cmmd, F_OK))) /* /bin/ls */
	{
		_cmmd = malloc(sizeof(char) * cmmd_length + 1);
		strcpy(_cmmd, cmmd);
		return (_cmmd);
	}
	else
	{
		strcpy(path_cp, path);

		_token = _strtok(path_cp, ":");
		while (_token != NULL)
		{
			dir_length = strlen(_token);

			strcpy(file_path, _token);
			strcat(file_path, "/");
			strcat(file_path, cmmd);
			strcat(file_path, "\0");

			if (!(stat(file_path, &bffr)))
			{
				_addr = malloc(sizeof(char) * cmmd_length + dir_length + 2);
				strcpy(_addr, file_path);
				return (_addr);
			}

			_token = _strtok(NULL, ":");
		}
	}
	return (NULL);
}
