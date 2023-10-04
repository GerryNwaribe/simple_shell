#include "main.h"

/**
 * main -
 * @argv:
 * @env:
 * Return:
*/
int main (int _cxt, _dou_p argv, _dou_p env)
{
    ssize_t _getline_Rv;
    size_t bffsz = 0;
    string bffr;
    int _exev_Rv;
    pid_t _child_PID_Rv;

    (void)_cxt;
    while (X_OK)
    {
        if (isatty(STDIN_FILENO) != 0)
            _print_string("[$] ");

        _getline_Rv = getline(&bffr, &bffsz, stdin);
        if (_getline_Rv == ERROR)
        {
            free(bffr);
            return (-1);
        }

        _child_PID_Rv = fork();
        if (_child_PID_Rv == ERROR)
        {
            free(bffr);
            exit(EXIT_FAILURE);
        }
        else if (_child_PID_Rv == 0)
        {
            /* Execution by the Child process */
            _exev_Rv = execve(bffr, argv, env);
            if (_exev_Rv == ERROR)
                _print_string("arv[0]: No such file or directory\n");
        }
        else
        {

        }


        free(bffr);
        bffr = NULL;
        bffsz = 0;
    }


    free(bffr);
    return (0);
}
