#include "main.h"

/**
 * main - Simple Shell main function.
 * @argv: double pointer for strings on stdin.
 * @_cxt: stdin word count.
 * @env: Environmental variable.
 * Return: returns 0 on success.
 */
int _alias(dou_p local_argv, size_t line_num, dou_p argv, dou_p _cmm)
{
    /**
     * implementation.. alias [name[='value'] ...]
     * alias: name='value' ##prints all alias
     * alias ls_alias=/bin/ls 
    */

    static _list **stt_list;
    _list *head = NULL;
    _list *shifter = NULL;
    _list *new = malloc(sizeof(_list));

    (void)line_num, (void)argv, (void)_cmm;
    new->name_value = local_argv[1];
    new->next = NULL;

    head = new;
    *stt_list = head;

    for (shifter = *stt_list; shifter; shifter = shifter->next)
        printf("%s\n", shifter->name_value);

    free(new);
    return (0);
}
