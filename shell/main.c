#include "main.h"

/**
 * main -
 * @argv:
 * @env:
 * Return:
*/
int main (int _cxt, _dou_p argv, _dou_p env)
{
    ssize_t _getline_Rv; /* Num of chars read from getline | can used to malloc the right size */
    size_t bffsz = 0;
    string bffr_s, bffr_h;
    int _exev_Rv;
    char *delimiters = " \n";
    char** token;
    pid_t _child_PID_Rv;

    (void)_cxt;
    while (X_OK)
    {

/* ================== isatty == 1 for "It is interactive" ========= */
        if (isatty(STDIN_FILENO))
            _print_string("[$] ");

/* ===================== End_of_ISATTY | Start_of_Execve ====================== */
        _getline_Rv = getline(&bffr_s, &bffsz, stdin);
        if (_getline_Rv == ERROR)
        {
            free(bffr);
            return (-1);
        }
/* ===================== End_of_getline | Start_of_STRTOK ====================== */

        bffr = malloc(sizeof(char) * _getline_Rv);

        _strcpy(bffr_h, bffr_s);

        token = strtok(bffr_h, delimiters);



 /* ===================== End_of_STRTOK | Start_of_Execve ====================== */
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
/* ===================== End_of_Execve ====================== */

        free(bffr);
        bffr = NULL;
        bffsz = 0;
    }


    free(bffr);
    return (0);
}
