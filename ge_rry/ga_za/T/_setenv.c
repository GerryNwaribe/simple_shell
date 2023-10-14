#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// You may have a main.h file with prototypes for _strlen, _strcpy, and _strcat
// Declare environ here if it's not included in main.h
extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
    if (name == NULL || value == NULL)
    {
        return -1; // Invalid input
    }

    char **env = environ;
    char *new_var = malloc(strlen(name) + strlen(value) + 2); // +2 for '=' and null terminator

    if (new_var == NULL)
    {
        perror("Memory allocation failed");
        return -1;
    }

    strcpy(new_var, name);
    strcat(new_var, "=");
    strcat(new_var, value);

    if (overwrite)
    {
        // If 'overwrite' is 1, replace the existing variable
        while (*env)
        {
            if (strncmp(name, *env, strlen(name)) == 0)
            {
                // Replace the existing variable
                *env = new_var;
                free(new_var);
                return 0;
            }
            env++;
        }
    }

    // If 'overwrite' is 0 or the variable doesn't exist, add the new variable
    char **new_env = malloc(sizeof(char *) * (env - environ + 2));

    if (new_env == NULL)
    {
        perror("Memory allocation failed");
        free(new_var);
        return -1;
    }

    env = environ;
    while (*env)
    {
        *new_env = *env;
        new_env++;
        env++;
    }
    *new_env = new_var;
    new_env++;
    *new_env = NULL;

    environ = new_env; // Update the environment pointer

    return 0;
}

int main()
{
    _setenv("MY_VARIABLE", "new_value", 1);

    // Access the updated variable
    char *value = getenv("MY_VARIABLE");
  
    char **dx = environ;

    for (; *dx; dx++)
    {
       printf("%s\n %s\n", *dx, value);
    }

    return 0;
}
