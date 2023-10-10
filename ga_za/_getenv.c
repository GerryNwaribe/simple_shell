#include "main.h"

/**
 * _getenv - 
 * @str:
 * Return: 
 */
string _getenv(string str)
{
    size_t lx = _strlen(str);
    _dou_p _env_cp = environ;

    for (; *_env_cp; ++_env_cp)
    {
        if (!(strncmp(*_env_cp, str, lx)) && (*_env_cp)[lx] == '=')
        {
            return (&(*_env_cp)[lx + 1]);
        }

    }
    return (NULL);
}
