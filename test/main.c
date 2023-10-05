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
    string bffr_Getline, bffr_h;
    int _exev_Rv, _status, token_idx;
    char *_delimiters = " \n", *token;
    pid_t _child_PID_Rv;

    (void)_cxt;
    while (X_OK)
    {

        /* ================== isatty == 1 for "It is interactive" ============= */
        if (isatty(STDIN_FILENO))
            _print_string("[$] ");

        /* ===================== End_of_ISATTY | Start_of_Execve ============== */
        _getline_Rv = getline(&bffr_Getline, &bffsz, stdin);
        if (_getline_Rv == ERROR)
        {
            free(bffr_Getline);
            return (-1);
        }
        /* ================== End_of_getline | Start_of_STRTOK ============== */

        bffr_h = malloc(sizeof(char) * _getline_Rv);    /* Making allocation on heap */
        if (bffr_h == NULL) /* Malloc check */
        {
            perror("hsh: memory allocation error");
            return (ERROR);
        }

        _strcpy(bffr_h, bffr_Getline);  /* Copying from the stack to the heap */

        token = strtok(bffr_h, _delimiters);
        while (bffr_h != NULL) /* Determining how many delimitable words there are */
        {
            token_idx++;
            token = strtok(NULL, _delimiters);
        }
        token_idx++;

        argv = malloc(sizeof(char *) * token_idx);

        token = strtok(bffr_h, _delimiters);
        for (token_idx = 0; token != NULL; token_idx++)
        {
            argv[token_idx] = malloc(sizeof(char) * _strlen(token));
            _strcpy(argv[token_idx], token);

            token = strtok(NULL, _delimiters);
        }
        argv[token_idx] = NULL;

        /* ================== End_of_STRTOK | Start_of_Execve ============= */
        _child_PID_Rv = fork();
        if (_child_PID_Rv == ERROR)
        {
            free(bffr_h);
            exit(EXIT_FAILURE);
        }
        else if (_child_PID_Rv == 0)
        {
            /* Execution by the Child process */
            _exev_Rv = execve(bffr_h, argv, env);
            /* if (_exev_Rv == ERROR)
                _print_string("arv[0]: No such file or directory\n"); */
        }
        else
        {
            wait(_status);
        }
        /* ======================== End_of_Execve =========================== */

        /* Freeing & Nullifying mallocs & Setting size = zero | Before next iteration */
        free(bffr_h);
        bffr_h = NULL;
        free(bffr_Getline);
        bffr_Getline = NULL;
        // free(**argv)
        bffsz = 0;
    }

    /*free(bffr_h);
    free(bffr_Getline);*/
    return (0);
}
