#include "main.h"

/**
 * _tokenization -
 * @str:
 * Return:
 *
 */
_dou_p _tokenization(string str, string _delimiters)
{

    string token;
    int i = 0, _idx = 0;
    _dou_p local_argv;

    i = 0;
    while (str[_idx] != '\0')
    {
        if (_strchr(_delimiters, str[_idx]))
            i++;
        _idx++;
    }

    local_argv = malloc(sizeof(char*) * (i + 1));

    token = _strtok(str, _delimiters);
    
    _idx = 0;
    while (token != NULL)
    {
        local_argv[_idx] = token;
        _idx++;
        token = _strtok(NULL, _delimiters);
    }
    local_argv[_idx] = NULL;

    return (local_argv);
}
