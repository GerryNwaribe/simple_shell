#include "main.h"

/**
 * _print_string - 
 * @st:
 * 
*/
int _print_string(string st)
{
    int x, idx;
    
    for (x = 0; st[x]; x++)
    {
        idx += _putchar(st[x]);
    }
    return (idx);

}
