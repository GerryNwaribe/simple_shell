#include "main.h"

/**
 * _setenv - Function to set or update an environment variable
 * @dou_argv: [0] Name of the environment variable
 *              [1] Value to assign to the environment variable.
 * @argv: UNUSED argument vector.
 * @line_num: UNUSED line count.
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(dou_p dou_argv, size_t line_num, dou_p argv)
{
    
    char *name = dou_argv[1]/*, *tmp = NULL*/;
    char **env = environ;
    int x = 0;

    (void)line_num;
    (void)argv;
    if (name == NULL)   /* Invalid input OR Mem err */
    {
        perror("unsetenv VARIABLE");
        return (-1);
    }

    for (; *env; x++, env++)                                            /* If 'overwrite' is 1, replace the existing variable */
    {
        if (!(_strncmp(name, *env, _strlen(name))))                     /* Replace the existing variable */
        {
            for (; environ[x]; x++)
            {
                environ[x] = environ[x + 1];
            }

            free(*env);
            return(0);
        }
        
    }
    
    return (-1);
}


/*int _unsetenv(const char *name) {
    if (name == NULL) {
        perror("unsetenv VARIABLE");
        return -1; // Invalid input
    }

    
    size_t name_length = strlen(name);

    for (int i = 0; environ[i]; i++) {
        if (strncmp(name, environ[i], name_length) == 0 && environ[i][name_length] == '=') {

            for (int j = i; environ[j]; j++) {
                environ[j] = environ[j + 1];
            }

            return 0; 
        }
    }

    return -1; 
}*/

