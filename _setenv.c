#include "main.h"

/**
 * _setenv - Function to set or update an environment variable
 * @dou_cmm: [0] Name of the environment variable
 *              [1] Value to assign to the environment variable.
 * @argv: UNUSED argument vector.
 * @line_num: UNUSED line count.
 * Return: 0 on success, -1 on failure
 */
int _setenv(dou_p dou_cmm, size_t line_num, dou_p argv, dou_p first_cmm)
{

	char *name = dou_cmm[1], *___bff = NULL;
	char *value = dou_cmm[2];
	char **env = environ;
	char new_var[_BFFSZ];
	int dx = 0;

	(void)line_num, (void)argv, (void)_head_;
	_free(first_cmm, 0);
	if (name == NULL || value == NULL)
	{
		perror("[(setenv VARIABLE VALUE)]");
		return (-1); /* Invalid input OR Mem err */
	}
	strcpy(new_var, name);
	strcat(new_var, "=");
	strcat(new_var, value);

	while (*env) /* If 'overwrite' is 1, replace existing variable */
	{
		if (!(strncmp(name, *env, strlen(name)))) /* Replace existing variable */
		{
			strcpy(environ[dx], new_var);
			return (0);
		}

		dx++;
		env++;
	}
	___bff = malloc(sizeof(char) * (strlen(new_var) + 1));
	strcpy(___bff, new_var);
	environ[dx++] = ___bff;
	environ[dx] = '\0';

	return (0);
}
