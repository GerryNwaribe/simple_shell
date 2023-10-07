#include "main.h"

/**
 *
 *
 */

/*char *_strtok(char *str, char *_delimiters)
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
            if (_str)
                *_shifter = '\0';

            return (rv);
        }
        _shifter++;
    }

    _str = _shifter;

    return (rv);
}

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


if (str != NULL || _delimiters != NULL)
   {
     while (strchr(_delimiters, *_str) != NULL)
    {
      if (*_str == '\0')
        return (NULL);
      _str++;
    }
     
    }
    
    _shifter = _str;
    rv = _shifter;

    x = 0;
    while (*_shifter)
    {
        if (strchr(_delimiters, _shifter[x]))
        {

            _str = _shifter + 1;
            if (_str)
                *_shifter = '\0';

            return (rv);
        }
        _shifter++;
    }

    _str = _shifter;

    return (rv);
}

