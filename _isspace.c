#include "main.h"

/**
 * _tokenization - Takes the string from stdin and tokenize into dou_p
 * @gtln: The string to be tokenized.
 * @_delimiters: The string of delimiters for parsing.
 * Return: A Double pointer.
 *
 */
int _isblnk(char *str)
{
    int i;

    for (i = 0; str[i]; i++)
        if (!isspace((unsigned char)str[i]))
            return 0;   /* Found a non-whitespace character */

    return 1;       /* All characters are whitespace */
}
