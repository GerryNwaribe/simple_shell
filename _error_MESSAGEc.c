#include "main.h"

/**
 * _error_MESSAGE - Handles the error_MESSAGE of invalid cmmds
 * @argv: Command line argument.
 * @line_num: line number
 * @key_w: to differencite betwwen cd err & addr err
 * @dou_cmmd: Holds the invalid entry.
 * Return: void
 */
void _error_MESSAGE(dou_p argv, size_t line_num, dou_p dou_cmmd, string key_w)
{
    fprintf(stderr, "%s: ", argv[0]);

    if (!(strcmp("cd", key_w)))
    {
        fprintf(stderr, "%lu: ", line_num);
        fprintf(stderr, "%s: can't cd to ", dou_cmmd[0]);
        fprintf(stderr, "%s\n", dou_cmmd[1]);
    }
    else if (!(strcmp("addr", key_w)))
    {
        fprintf(stderr, "%lu: ", line_num);
        fprintf(stderr, "%s: not found\n", dou_cmmd[0]);
    }
    else
        fprintf(stderr, "No such file or directory\n");
    
    _free(dou_cmmd, 1);
}
