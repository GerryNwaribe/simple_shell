#include <stdlib.h>
#include <stdio.h>


void _free(void *_malloc, int is_dou_p)
{
    if (_malloc == NULL)
    {
        return;
    }

    if (is_dou_p)
    {
        void **alloc = (void **)_malloc;
        if (alloc[0])
        {
            for (int x = 0; alloc[x]; x++)
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


int main() {
    // Allocate a single pointer
    int *single_ptr = malloc(sizeof(int));
    *single_ptr = 5;

    // Allocate a double pointer
    int **double_ptr = malloc(sizeof(int*));
    *double_ptr = malloc(sizeof(int));
    **double_ptr = 10;

    _free(single_ptr, 0);
    _free(double_ptr, 1);
    return 0;
}
