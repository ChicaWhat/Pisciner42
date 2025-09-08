/*
	Cambia los data de la siguiente lista por x y retorna la lista
	con todos los valores cambiados.
*/

#include "nodes.h"

t_node *ft_change(t_node *nodes, int x)
{
		t_node *first = nodes;
		while (nodes)
		{
				if (nodes->data != x)
						nodes->data = x;
				else
						nodes = nodes->next;
		}
		return (first);
}
