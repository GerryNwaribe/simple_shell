#include "main.h"

/**
 * _alias - This function creates and applies alaises.
 * @_cmmd: double pointer for strings on stdin.
 * @ln_nm: stdin word count.
 * @av: Environmental variable.
 * @_cmm: dou command in splits.
 * Return: returns 0 on success.
 */
int _alias(dou_p _cmmd, size_t ln_nm, dou_p av, dou_p _cmm)
{
	_list *tmp = *_head_;	/* alias: name='value' ##prints all alias */
	_list *new = NULL;		/* implementation.. alias [name[='value'] ...] */
	int nod_num = 0;		/* alias ls_alias=/bin/ls */

	(void)ln_nm, (void)av, (void)_cmm;
	if (_cmmd[1])
	{
		new = malloc(sizeof(_list));
		if (new == NULL)
			return (ERROR);
		new->_value = strdup(_cmmd[1]);
		new->next = *_head_;
		*_head_ = new;

		return (0);
	}
	else
	{
		for (; tmp != NULL; nod_num++, tmp = tmp->next)
		{
			if (tmp == NULL)
				_print_string("(nil) list\n");
			else
			{
				_print_string("alias");
				_print_string(tmp->_value);
			}
		}
		return (nod_num);
	}
	return (-1);
}
