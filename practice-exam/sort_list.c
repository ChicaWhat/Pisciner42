#include "list.h"

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
		int tmp;
		t_list *first = lst;

		if (*lst == NULL || lst == NULL)
				return ;

		while (lst && lst-next != NULL) // mientras el nodo en el que estoy exista Y ADEMÁS el nodo siguiente no apunte a NULL, entro en el bucle
		{
				if((*cmp)(lst->data, lst->next->data) == 0)
				{
						tmp = lst->data;
						lst->data = lst->next->data;
						lst->next->data = tmp;
						lst = first;
				}
				else
						lst = lst->next;
		}
		return (first);
}
