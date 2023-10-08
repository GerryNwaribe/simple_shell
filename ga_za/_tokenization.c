#include "main.h"

/**
 * _tokenization -
 * @str:
 * Return:
 *
 */
_dou_p _tokenization(char *str, char *_delimiters)
{

    char *token;
    int i = 0, token_idx = 0;
    _dou_p local_argv;

    i = 0;
    while (str[token_idx] != '\0')
    {
        if (strchr(_delimiters, str[token_idx]))
            i++;
        token_idx++;
    }
    i++;

    local_argv = malloc(sizeof(char *) * (i + 1));

    token = strtok(str, _delimiters);
    token_idx = 0;
    while (token != NULL)
    {
        local_argv[token_idx] = token;
        token_idx++;
        token = strtok(NULL, _delimiters);
    }
    local_argv[token_idx] = NULL;

    return (local_argv);
}
