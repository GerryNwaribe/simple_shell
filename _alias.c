#include "main.h"

/**
 * _alias - This function creates and effect alaises.
 * @dou_av: double pointer for strings on stdin.
 * @ln_nm: stdin word count.
 * @av: Environmental variable.
 * @_cmm: dou command in splits.
 * Return: returns 0 on success.
 */
int _alias(dou_p dou_av, size_t ln_nm, dou_p av, dou_p _cmm)
{
	/**
	 * implementation.. alias [name[='value'] ...]
	 * alias: name='value' ##prints all alias
	 * alias ls_alias=/bin/ls
	 */

	static _list **stt_list;
	_list *head = NULL;
	_list *shifter = NULL;
	_list *new = malloc(sizeof(_list));

	(void)ln_nm, (void)av, (void)_cmm;
	new->name_value = dou_av[1];
	new->next = NULL;

	head = new;
	*stt_list = head;

	for (shifter = *stt_list; shifter; shifter = shifter->next)
		printf("%s\n", shifter->name_value);

	free(new);
	return (0);
}
