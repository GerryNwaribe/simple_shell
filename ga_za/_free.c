#include "main.h"

/**
 *
 *
 */
void _free(void *_malloc, int is_dou_p)
{
    int x;
    if (_malloc == NULL)
    {
        return;
    }

    if (is_dou_p)
    {
        void **alloc = (void **)_malloc;
        if (alloc[0])
        {
            for (x = 0; alloc[x]; x++)
            {
                if (alloc[x])
                {
                    free(alloc[x]);
                }
            }
        }
    }

    free(_malloc);

    return;
}
