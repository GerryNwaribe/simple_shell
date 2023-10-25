#include "main.h"

/**
 * _nll_nwln -
 * @gtln:
 * @read:
 * Return:
 */
string _nll_nwln(string gtln, ssize_t read)
{
    /*char _gtln[_BFFSZ];
    string __gtln = NULL;*/

    if (_isblnk(gtln))     /* if what's in gtln is "\n\0" OR whitespaces */
    {
        /*_free(gtln, 0);*/
        return (NULL);
    }

    if ((read != EOF) && (gtln[read - 1] == '\n'))
    {
        /*printf("%s\n", gtln);
        strcpy(_gtln, gtln);

        _free(gtln, 0);
        __gtln = strdup(_gtln);*/
        gtln[read - 1] = '\0';

        return (gtln);
    }
    
    return (gtln);
}
