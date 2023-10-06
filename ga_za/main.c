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

        /* ================== [isatty == 1 for "It is interactive"] ============ */
        if (isatty(STDIN_FILENO))
            _print_string("[$] ");
        /* ===================== [End_of_ISATTY || Start_of_Getline] ============== */
        _getline_Rv = getline(&getline_bffr, &bffsz, stdin);
        if (_getline_Rv == ERROR)
        {
            _putchar('\n');
            exit(ERROR);
        }
        /* ===================== [Tokenizer] ========================== */
        local_argv = _tokenization(getline_bffr, " \n\t\r");

        printf("%s\n", local_argv[0] == NULL ? "(null)" : local_argv[0]);

        /* ======== [If only '\n' OR Enter Button] ========== */
        if (local_argv[0] == NULL)
        {
            continue;
        }

        /* ============ [If input equals EXIT] ==============*/
        if (strcmp(local_argv[0], "exit") == 0)
        {
            exit(ERROR);
        }
            

        /* ================== [End of tokenizeer || Start of Execve] ============= */
        execmd(local_argv, env);

        /* ======================== ###### =========================== */

        /* Freeing & Nullifying mallocs & Setting size = zero | Before next iteration */
        if (local_argv != NULL)
        {
            free(local_argv);
            local_argv = NULL;
        }
        if (isatty(STDIN_FILENO) == 0)
        {
            break;
        }
            
        if (getline_bffr != NULL)
        {
            free(getline_bffr);
            getline_bffr = NULL;
        }
    }

   if (getline_bffr != NULL)
        free(getline_bffr);

    return (0);
}
