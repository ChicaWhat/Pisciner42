/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:49:39 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/27 13:01:02 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

//--- Función que crea el primer nodo reservando memoria e inicializa todos los varoles ---//
t_node	*create_node(long num, int size)
{
	t_node	*new_node;

	new_node = malloc(1 * sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->index = 0;
	new_node->pos = 1;
	new_node->size = size;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->total_cost = 0;
	new_node->cheapest = 0;
	new_node->target = 0;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}
//--- Función que crea un segundo nodo y lo enlaza a la lista doblemente enlazada---//
void	add_new_node(t_node **node1, long num, int size)
{
	t_node	*node2;

	node2 = create_node(num, size);
	if (!node2)
		return;
	(*node1)->next = node2; 
	node2->next = (*node1);
	(*node1)->prev = node2; 
	node2->prev = (*node1);
}
//--- Función necesaria para enlazar cuando tenemos más de 2 nodos en la lista ---// 
void	add_more_nodes(t_node **stack, t_node **node)
{
	(*stack)->prev->next = (*node);
	(*node)->next = (*stack);
	(*node)->prev = (*stack)->prev;
	(*stack)->prev = (*node);
}
//--- Función que crea el stack sin los valores actualizados todavía ---//
t_node	*create_stack(long *list_num, int size)
{
	int		i;
	t_node	*node1;
	t_node	*node2;

	node1 = create_node(list_num[0], size);
	if (!node1)
		return (NULL);
	add_new_node(&node1, list_num[1], size);
	if (node1->next == node1)
		return (ft_free_all(NULL, NULL, &node1));
	i = 2;
	while (i < size)
	{
		node2 = create_node(list_num[i], size);
		if (!node2)
		{
			free(node1);
			//free(list_num);
			return (NULL);
		}
		add_more_nodes(&node1, &node2);
		i++;
	}
	//free(list_num);
	return (node1);
}
//--- Función que ''rellena'' cada nodo de la pila con el numnj y el size de dicha lista ---//
t_node	*init_stack(char **av)
{
	char	*one_av;
	char	**list;
	int		size;
	long	*list_num;
	t_node	*stack_a;

	one_av = ft_one_argv(av);
	if (!one_av)
		return (NULL);
	list = ft_split_argv(one_av);
	if (!list)
		return (NULL);
	size = list_size(list);
	list_num = ft_convert_to_long_array(list, size);
	if (!list_num)
		return (NULL);
	stack_a = create_stack(list_num, size);
	if (!stack_a)
	{
		free(list_num);
		return (NULL);
	}
	free(list_num);
	ft_free_all(list, NULL, NULL);
	return (stack_a);
}
