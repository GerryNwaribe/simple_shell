#include "main.h"

/**
 * main -
 * @name:
 * @value:
 * @over_write:
 * Return:
 */
int _setenv(const char *name, const char *value, int over_write)
{
    char **env = environ;
    int i = _strlen(env);

    char *nm = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));

    _strcpy(nm, name);
    _strcat(nm, "=");
    _strcat(nm, value);
    _strcat(nm, "\0");

    *env = nm;
    return (0);

    /*if (!(_strncmp(name, *env, (_strlen(name) + 1))))
    {
    }
    for (; *env; env++)
    {
    }*/
    return (-1);
}
