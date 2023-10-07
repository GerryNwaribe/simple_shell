#include "main.h"

/**
 *
 *
 */

char *_strtok(char *str, char *_delimiters)
{
    static char *_str;
    char *_shifter, *rv;
    int x;

    if (str)
        _str = str;

    if (*_str == '\0')
        return (NULL);

    _shifter = _str;
    rv = _shifter;

    x = 0;
    while (*_shifter)
    {
        if (_strchr(_delimiters, _shifter[x]))
        {

            _str = _shifter + 1;
            *_shifter = '\0';

            return (rv);
        }
        _shifter++;
    }

    _str = _shifter;

    return (rv);
}
