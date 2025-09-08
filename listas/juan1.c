/*
	Encuentra en la siguiente lista enlazada el nodo con valor 3.
	En caso de no encontrarlo, retorna NULL.
*/

#include "nodes.h"

t_node	*ft_find(t_node *nodes)
{
		while (nodes)
		{
				if (nodes->data != 3)
						nodes = nodes->next;
				else
						return (nodes);
		}
		return (NULL);
}
