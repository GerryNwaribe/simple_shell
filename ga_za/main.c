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
    /*int _exev_Rv, _status;
    pid_t _child_PID_Rv;*/

    (void)_cxt;
    while (X_OK)
    {

        /* ================== isatty == 1 for "It is interactive" ============= */
        if (isatty(STDIN_FILENO))
            _print_string("[$] ");

        /* ===================== End_of_ISATTY | Start_of_Getline ============== */
        _getline_Rv = getline(&getline_bffr, &bffsz, stdin);
        if (_getline_Rv == ERROR)
        {
            _putchar('\n');
            break;
        }

        /* ===================== tokenizer ========================== */

        local_argv = _tokenization(getline_bffr);
        /*local_argv = tokenize_string(getline_bffr, " \n\t\r");*/

        if (local_argv[0] == NULL)
            continue;

        /*printf("%s\n", local_argv[0]);
        if (local_argv[1] != NULL)
                    printf("%s\n", local_argv[1]);*/

        if (_strcmp(local_argv[0], "exit") == 0)
        {
            break;
        }

        /* ================== End of tokenizeer ===== Start of Execve ============= */

        execmd(local_argv, env);

        /*_child_PID_Rv = fork();
        if (_child_PID_Rv < 0)
        {
            perror("Fork");
            free(local_argv);
            exit(EXIT_FAILURE);
        }
        else if (_child_PID_Rv == 0)
        {

            _exev_Rv = execve(local_argv[0], local_argv, env);                  Execution by the Child process
            if (_exev_Rv == ERROR)
                perror("Error");
        }
        else
        {
            wait(&_status);
        }
          ======================== End_of_Execve =========================== */

        /* Freeing & Nullifying mallocs & Setting size = zero | Before next iteration */
        if (local_argv != NULL)
        {
            free(local_argv);
            local_argv = NULL;
        }
        if (isatty(STDIN_FILENO) == 0)
            break;
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
