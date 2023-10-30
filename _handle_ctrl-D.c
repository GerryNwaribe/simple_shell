#include "main.h"

/**
 * main - 
 * @argv:
 * @_cxt:
 * @env:
 * Return:
 */

void _handle_ctrl_D(int signal)
{
   (void)signal, (void)_head_;
   /**
    * if (___bff != NULL)
    * {
    * free(___bff);
    *  ___bff = NULL;
    * }
    * if (isatty(STDIN_FILENO))
    * {
    * _print_string("\n");
    * }
    * */

    exit(0);
}
