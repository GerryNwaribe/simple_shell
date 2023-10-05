#include "main.h"

/**
 * 
 * 
*/
int main(int argc, char** argv, char** env)
{
    while(X_OK)
    {
        char** _argv;
        char* bffr;
        size_t bffsz;

        _print_string("[$#] ");
        ssize_t GL = getline(&bffr, &bffsz, stdin);
        if (GL == ERROR)
            return (ERROR);
        
        if (bffr[GL - 1] == '\n')
            bffr[GL -1 ] = '\0';
        
        char* tokenptr = strtok(bffr, " \n");
        
        int i = 0;
        while (tokenptr != NULL)
        {
            _argv[i] = tokenptr;
            i++;
            tokenptr = strtok(NULL, " \n");
        }
        argv[i] = NULL;

        tokenptr = strtok(bffr, " \n"); 
        i = 0;
        while (argv[i] != NULL)
        {
            printf("%s\n", argv[i]);
            i++;
        }

        free(bffr);
        bffsz = 0;        
    }
}
