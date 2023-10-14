#include "main.h"

/**
 * _free - This Function frees any kind of malloc (integer or string).
 * @_malloc: The memory location to be freed.
 * @is_dou_p: An indication for whether it is a array of pointers or not.
 * Return: Void.
 */
void _free(void *_malloc, int is_dou_p)
{
	int x = 0;

	if (_malloc == NULL)
		return;

	if (is_dou_p)
	{
		void **alloc = (void **)_malloc;

		for (; alloc[x]; x++)
		{
			if (alloc[x])
				free(alloc[x]);
		}
	}

	free(_malloc);
}
