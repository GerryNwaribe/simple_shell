#include "main.h"

/**
 * execmd -
 * @argv:
 *
 */
void execmd(_dou_p local_argv, _dou_p env)
{

    /*int _status, _exev_Rv;
    pid_t _child_PID_Rv;*/
    string cmmd, atl_cmmd;
    int _exev_Rv;

    (void)env;
    if (local_argv)
    {
        cmmd = local_argv[0];
        atl_cmmd = NULL;

        _exev_Rv = execve(atl_cmmd, local_argv, NULL);
        if (_exev_Rv == -1)
            perror("Error");
    }

    /* _child_PID_Rv = fork();
        if (_child_PID_Rv < 0)
        {
            perror("Fork");
            if (local_argv != NULL)
                free(local_argv);
            exit(EXIT_FAILURE);
        }
        else if (_child_PID_Rv == 0)
        {
            _exev_Rv = execve(local_argv[0], local_argv, env);          Execution by the Child process
            if (_exev_Rv == ERROR)
                perror("Error");
        }
        else
        {
            wait(&_status);
        }*/
}
