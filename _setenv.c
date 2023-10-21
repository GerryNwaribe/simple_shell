#include "main.h"

/**
 * _setenv - Function to set or update an environment variable
 * @dou_cmm: [0] Name of the environment variable
 *              [1] Value to assign to the environment variable.
 * @argv: UNUSED argument vector.
 * @line_num: UNUSED line count.
 * Return: 0 on success, -1 on failure
 */
int _setenv(dou_p dou_cmm, size_t line_num, dou_p argv)
{

	char *name = dou_cmm[1], *bff = NULL;
	char *value = dou_cmm[2];
	char **env = environ;
	char new_var[_BFFSZ];
	int dx = 0;

	/* +2 for '=' and null terminator */
	(void)line_num;
	(void)argv;
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

	bff = malloc(sizeof(char) * (strlen(name) + strlen(value) + 2));
	environ[dx++] = bff;
	environ[dx] = '\0';
	return (0);
}
