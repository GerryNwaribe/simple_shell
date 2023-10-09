#include "main.h"

/**
 * _env -
 * Void input and output.
 */
void _env()
{
    extern _dou_p environ;
    _dou_p dx;

    for (dx = environ; *dx; dx++)
    {
        _print_string(*dx);
        _putchar('\n');
    }
}
