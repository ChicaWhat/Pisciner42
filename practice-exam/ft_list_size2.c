#include "list.h"

int ft_list_size(t_list *begin_list)
{
		int i = 0; // Declaramos variable para saber el tamaño de la lista
		if (!begin_list) // Tengo lista que contar?
				return (i);

		i = 1; // Reasignamos el valor, porque se empieza a contar desde 1
		while (begin_list->next != NULL) // Mientras el next de mis nodos sean distintos de NULL, entro
		{
				begin_list = begin_list->next; // El nodo ahora va a apuntar al next del siguiente nodo
				i++; // Sumo +1 a mi contador
		}
		return (i); // Retorno el contador
}
