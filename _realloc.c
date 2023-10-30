#include "main.h"

/**
 * _realloc - Reallocate memory for a pointer with new size.
 *
 * @ptr: Pointer to the memory block to reallocate.
 * @new_size: New size (in bytes) for the reallocated memory block.
 * Return: A pointer to the reallocated memory block or NULL on failure.
 */
void *_realloc(void *ptr, size_t new_size)
{
	char *new_mem = NULL;
	char *temp_ptr = ptr;

	(void)_head_;

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr && new_size)
		return (malloc(new_size));

	new_mem = malloc(new_size);
	if (!new_mem)
		return (NULL);

	strncpy(new_mem, temp_ptr, new_size);

	free(ptr);
	return (new_mem);
}
