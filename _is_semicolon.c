#include "main.h"

/**
 * _is_semicolon -
 * @gtln:
 * Return:
 */
int _is_semicolon(string gtln)
{
    if (strchr(gtln, ';'))
        return (1);

    return (0);
}
