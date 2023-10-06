#include  "../main.h"
/**
 * 
 * main -
 * 
 * 
 */

void freemem(char **args);


int main(void)
{
	int i = 0;
	char *content = NULL;
	size_t buffsize = 0;
	size_t bytereturned = 0;
	char *token = NULL;
	int interactive = 1;


	while (1)
	{
		interactive = isatty(STDIN_FILENO);

		char **args = malloc(10 * sizeof(char *));

		if (interactive != 0)
			write(1, "$ ", 2);

		i = 0;
		bytereturned = getline(&content, &buffsize, stdin);

		token = strtok(content, " \n\t\r");
		while (token != NULL)
		{
			args[i] = malloc(sizeof(char) * (strlen(token) + 1));
			strcpy(args[i], token);
			i++;
			token = strtok(NULL, " \n\t\r");
		}


		if (i == 0)
		{
			free(args);
			continue;
		}
		args[i] = NULL;
		
		if (strcmp(args[0], "exit") == 0)
		{
			freemem(args);
			break;

		}
		if (bytereturned > 1)
		{

			if (args[0] != NULL)
			{
				freemem(args);
			}
		}
		if (interactive == 0)
			break;

	}
	if (content != NULL)
		free(content);

}


/* ============================================ */


void freemem(char **args)
{
	if (args == NULL)
		return;
	for (int j = 0;  args[j]; j++)
	{
		if (args[j] != NULL)
		{
			free(args[j]);
		}
	}
	if (args != NULL)
		free(args);
}


/* ============================================ */


