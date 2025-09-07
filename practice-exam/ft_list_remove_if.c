#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
		if (begin_list == NULL || (*begin_list) == NULL)
				return ;
		t_list *tmp = (*begin_list);

		while ((*being_list))
		{
				if (cmp(tmp->data, data_ref) == 0)
				{
						(*begin_list) = tmp->next;
						free(tmp);
						tmp = (*begin_list);
				}
				else
				{
						tmp = (*begin_list->next);
						(*begin_list) = (*begin_list)->next;
				}
		}
}
