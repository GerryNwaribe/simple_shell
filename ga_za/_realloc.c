#include "main.h"

/**
 * _realloc - Reallocate memory for a pointer with new size.
 *
 * @ptr: Pointer to the memory block to reallocate.
 * @old_size: Previous size (in bytes) of the memory block.
 * @new_size: New size (in bytes) for the reallocated memory block.
 *
 * Return: A pointer to the reallocated memory block or NULL on failure.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
        unsigned int z;
        char *pxr;              /* Declare a character pointer variable pxr. */
        char *xld_pz;           /* Declare a character pointer variable xld_pz. */

        if (new_size == old_size)
                return (ptr);         /* If sizes are the same, no reallocation needed. */

        if (new_size == 0 && ptr)
        {
                free(ptr);          /* If new_size is 0 and ptr is not NULL, free memory. */
                return (NULL);
        }

        if (!ptr && new_size)
                return (malloc(new_size));  /* If ptr is NULL, allocate new memory. */

        pxr = malloc(new_size);      /* Allocate memory for the reallocated block. */
        if (!pxr)
                return (NULL);             /* Return NULL if memory allocation fails. */

        xld_pz = ptr;               /* Store the original pointer in xld_pz. */

        if (new_size < old_size)
        {
                for (z = 0; z < new_size; z++)
                        pxr[z] = xld_pz[z];  /* Copy data from old to new block. */
        }

        if (new_size > old_size)
        {
                /* Copy data from old to new block for sizes larger than the old block. */
                for (z = 0; z < old_size; z++)
                        pxr[z] = xld_pz[z];
        }

        free(ptr);            /* Free the old memory block. */

        return (pxr);        /* Return a pointer to the reallocated memory block. */
}
