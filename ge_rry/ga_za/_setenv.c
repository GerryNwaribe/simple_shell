#include "main.h"

/**
 * _setenv - Function to set or update an environment variable
 * @name: Name of the environment variable
 * @value: Value to assign to the environment variable
 * @overwrite: If 1, overwrite the variable if it already exists; if 0, do not overwrite
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{

    char **env = NULL;
    static char *new_var;
    char *tmp = NULL;
    new_var = malloc(sizeof(char) * (strlen(name) + strlen(value) + 2)); /* +2 for '=' and null terminator */
    if (name == NULL || value == NULL || new_var == NULL)
    {
        if (new_var == NULL)
            perror("Memory allocation failed");
        return (-1); /* Invalid input OR Mem err */
    }
    strcpy(new_var, name);
    strcat(new_var, "=");
    strcat(new_var, value);
    
    if (overwrite)
    {
        env = environ;
        while (*env) /* If 'overwrite' is 1, replace the existing variable */
        {
            if (!(strncmp(name, *env, strlen(name)))) /* Replace the existing variable */
            {
                tmp = *env;
                *env = new_var;
                free(tmp);
                return (0);
            }
            env++;
        }
    }

    env = environ;
    char **new_env = malloc(sizeof(char *) * _bffsz); /* If 'overwrite' is 0 or the variable doesn't exist, add the new variable */
    if (new_env == NULL)
    {
        perror("Memory allocation failed");
        free(new_var);
        return (-1);
    }

  char **temp = new_env;
  
    while (*env)
    {
        *new_env = *env;
        
        new_env++;
        env++;
    }

    
    *new_env = new_var;
    new_env++;
    *new_env = '\0';
    for (; *temp; temp++)
    {
    printf("%s\n", *temp);
    }
    /*environ = new_env;  Update the environment pointer */

    return (0);
}
