#include "main.h"

/**
 * _tokenize_slt_exec -
 * @getline_bffr:
 * @semi_colon:
 * @dou_argv:
 * @env:
 * @argv:
 * @line_num:
 * Return:
 */
int _tokenize_slt_exec(string getline_bffr, dou_p env, dou_p argv, size_t line_num)
{
    dou_p dou_argv = NULL, semi_colon = NULL;

    semi_colon = _tokenization(getline_bffr, ";"); /* Works fine for ';', not so well for '&&' and '||'*/

    for (; *semi_colon; semi_colon++)
    {
        dou_argv = _tokenization(*semi_colon, " \n\t\r");

        if (dou_argv && (!(_is_prsent(dou_argv[0]))))
        {
            _slt(dou_argv[0])(dou_argv, line_num, argv);
            continue;
        }

        _execmd(dou_argv, env, argv, line_num);
    }
    _free(dou_argv, 0);
    
    return (0);
}
