#include "main.h"

/**
 * main -
 * @argv:
 * @env:
 * Return:
*/
int main (int x, string_dp argv, string_dp env)
{
    (void)x;
    string prmpt = "\n[SHll][> ";
    string bffr = NULL;
    string arg[] = {NULL, NULL};
    size_t bffsz = 0;
    ssize_t getline_sz;
    pid_t child_ID;
    int _status, dz;


    for (; 1; )
    {
        _print_string (prmpt);


        getline_sz = getline (&bffr, &bffsz, stdin);
        if (getline_sz == -1)
        {
            _print_string("Exiting shell ...\n");
            free(bffr);
            return (-1);
        }



        dz = 0;
        while (bffr[dz])
        {
            if (bffr[dz] == '\n')
                bffr[dz] = 0;
            dz++;
        }


        arg[0] = strdup(bffr);
        child_ID = fork ();
        if (child_ID < 0)
        {
            _print_string ("Forking failed ...");
            free(bffr);
            return (-1);
        }
        else if (child_ID == 0)
        {
            if (execve (arg[0], arg, env) == -1)
                _print_string("Command does not exist ...\n");
        }
        else
            wait(&_status);


        /* _print_string (bffr); */
    }


    free (bffr);
    return (0);
}
