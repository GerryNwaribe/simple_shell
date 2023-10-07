#include "main.h"

/**
 * main -
 * @argv:
 * @env:
 * Return:
 */
int main(int _cxt, _dou_p argv, _dou_p env)
{
    ssize_t _getline_Rv; /* Num of chars read from getline | can used to malloc the right size */
    size_t bffsz = 0;
    string getline_bffr;
    _dou_p local_argv;

    (void)_cxt;
    while (X_OK)
    {
        if (isatty(STDIN_FILENO)) /* [isatty == 1 for "It is interactive"] */
            _print_string("[$] ");

        _getline_Rv = getline(&getline_bffr, &bffsz, stdin); /* [End_of_ISATTY || Start_of_Getline] */
        if (_getline_Rv == ERROR)
        {
            _putchar('\n');
            exit(EXIT_FAILURE);
        }

        local_argv = _tokenization(getline_bffr, " \n\t\r"); /* [Tokenizer] */

        /*printf("%s\n", local_argv[0] == NULL ? "(null)" : local_argv[0]);*/

        if (local_argv[0] == NULL) /* [If only '\n' OR Enter Button] */
            continue;

        if (strcmp(local_argv[0], "exit") == 0) /* [If input equals EXIT] */
            exit(EXIT_FAILURE);

        execmd(local_argv, env); /* [End of tokenizeer || Start of Execve] */

        if (isatty(STDIN_FILENO) == 0)
            break;
        _free(local_argv, 1);
        _free(getline_bffr, 0);
        
    }

    if (getline_bffr != NULL)
        _free(getline_bffr, 0);

    return (0);
}
