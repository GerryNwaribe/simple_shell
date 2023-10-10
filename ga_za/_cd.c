#include "main.h"

/**
 * _cd - This function.
 * @cmmd: The command from stdin who's path is to be found.
 * Return: void.
 */
void _cd(_dou_p cmmd)
{
    const char *hm = _getenv("HOME");
    const char *_pwd = _getenv("OLDPWD");

    if (cmmd[1])
    {

        if (_pwd)
        {
            if (!(_strcmp(cmmd[1], "-")))
            {
                if (chdir(_pwd))
                    perror("cd");
                return;
            }
                
        }

        if ((chdir(cmmd[1])))
            perror("cd");
    }
    else
    {
        if (hm)
        {
            if (chdir(hm))
                perror("cd");
        }
        else
            perror("cd");
    }
}
