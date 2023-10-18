#include "main.h"

/**
 * get_PATH - This function gets all PATHs
 *                          and determine the path for the command.
 * @cmmd: The command from stdin who's path is to be found.
 * Return: A pointer to valid PAth or NULL if it doesn't exist.
 */
string _get_PATH(string cmmd)
{
	int dir_length, _stat, __stat, cmmd_length;
	string path, path_cp, _token, file_path;
	struct stat bffr;

	path = _getenv("PATH");

	if (path)
	{
		path_cp = _strdup(path);
		cmmd_length = _strlen(cmmd);

		_token = _strtok(path_cp, ":");
		while (_token != NULL)
		{
			dir_length = _strlen(_token);
			file_path = malloc(cmmd_length + dir_length + 2);
			if (!file_path)
				free(file_path);
			_strcpy(file_path, _token);
			_strcat(file_path, "/");
			_strcat(file_path, cmmd);
			_strcat(file_path, "\0");
			_stat = stat(file_path, &bffr);
			if (_stat == 0)
			{
				_free(path_cp, 0);
				return (file_path);
			}
			_free(file_path, 0);
			_token = _strtok(NULL, ":");
		}
		_free(path_cp, 0);
		__stat = stat(cmmd, &bffr);
		if (__stat == 0)
			return (cmmd);
		return (NULL);
	}
	return (NULL);
}



#include "main.h"

/**
 * get_PATH - This function gets all PATHs
 *                          and determine the path for the command.
 * @cmmd: The command from stdin who's path is to be found.
 * Return: A pointer to valid PAth or NULL if it doesn't exist.
 */
string get_PATH(string cmmd)
{
	int dir_length, cmmd_length;
	string path = NULL, _token = NULL, _addr = NULL;
	char path_cp[_BFFSZ], file_path[_BFFSZ];
	struct stat bffr;

	path = getenv("PATH");
	
	if (path)
	{		
		_strcpy(path_cp, path);
		cmmd_length = _strlen(cmmd);

		_token = _strtok(path_cp, ":");
		while (_token != NULL)
		{
			dir_length = _strlen(_token);
			
			_strcpy(file_path, _token);
			_strcat(file_path, "/");
			_strcat(file_path, cmmd);
			_strcat(file_path, "\0");

			if (!(stat(file_path, &bffr)))
			{
				_addr = malloc(cmmd_length + dir_length + 2);
				strcpy(_addr, file_path);
				return (_addr);
			}

			_token = _strtok(NULL, ":");
		}

		if (!(stat(cmmd, &bffr)))		/* /bin/ls */
			return (cmmd);
	}
	return (NULL);
}

