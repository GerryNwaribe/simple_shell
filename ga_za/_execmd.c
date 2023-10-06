#include "main.h"

/**
 * execmd -
 * @argv:
 * 
*/
void execmd(_dou_p argv)
{
    int dxe;
    string _path = NULL;

    if (argv)
    {
        dxe = execve(_path, argv, NULL);
        if (dxe < 0)
        {
            perror("Error");
        }
    }
    return;
}
