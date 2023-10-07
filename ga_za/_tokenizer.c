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
        if (_strchr(_delimiters, str[token_idx]))
            i++;
        token_idx++;
    }
    i++;

    local_argv = malloc(sizeof(char *) * (i + 1));

    token = _strtok(str, _delimiters);
    token_idx = 0;
    while (token != NULL)
    {
        local_argv[token_idx] = token;
        token_idx++;
        token = _strtok(NULL, _delimiters);
    }
    local_argv[token_idx] = NULL;

    return (local_argv);
}


/*
_dou_p _tokenization(char* input)
{
    char* delimiters = " \n\t\r";
    int token_idx = 0, i = 0;
    char* token;
    char** result = NULL;
    char* input_copy = strdup(input);  // Create a copy of the input string

    if (input_copy == NULL) {
        perror("strdup");
        return NULL;
    }

    // Count the number of tokens
    char* token_count_copy = strdup(input_copy);
    if (token_count_copy == NULL) {
        perror("strdup");
        free(input_copy);
        return NULL;
    }

    char* token_count_ptr = token_count_copy;
    while (_strtok(token_count_ptr, delimiters) != NULL) {
        i++;
        token_count_ptr = NULL;
    }
    free(token_count_copy);

    result = (char**)malloc((i + 1) * sizeof(char*));
    if (result == NULL) {
        perror("malloc");
        free(input_copy);
        return NULL;
    }

    token = _strtok(input_copy, delimiters);
    while (token != NULL) {
        result[token_idx] = strdup(token);
        if (result[token_idx] == NULL) {
            perror("strdup");
            // Clean up and free memory on error
            for (int j = 0; j < token_idx; j++) {
                free(result[j]);
            }
            free(result);
            free(input_copy);
            return NULL;
        }
        token_idx++;
        token = _strtok(NULL, delimiters);
    }

    result[token_idx] = NULL;
    free(input_copy);

    return result;
}
*/
