#include "main.h"

/**
 * _free_alias -
 * Return:
 */
void _free_alias()
{
    _list *temp = *_head_;

    if (*_head_ == NULL || temp == NULL)
        return;


    while (_head_)
    {
        temp = (*_head_)->next;
        free((*_head_)->_value);
        free(*_head_);
        *_head_ = temp;
    }
}
