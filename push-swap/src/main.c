/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:44:38 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/01 21:24:47 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	char	*one_av;
	char	**list;

	if (ac == 1)
		return (0);
	one_av = ft_one_argv(av + 1);
	if (!one_av)
		ft_error();
	list = ft_split_argv(one_av);
	ft_parsing(list);
	stack_a = push_swap(list);
	if (!stack_a)
		return (1);
	ft_free_all(list, NULL, NULL);
	free_circular_list(&stack_a);
	return (0);
}

//--- Function to print all the information I need from the nodes ---//
/* void	print_nodes(t_node *node)
{
	t_node	*aux;

	if (!node)
		return ;
	
	aux = node;
	while (1)
	{
		printf("nodo %ld\n", aux->num);
		printf("index %d\n", aux->index);
		printf("target %ld\n", aux->target);
		printf("posicion %d\n", aux->pos);
		printf("cost_a %d\n", aux->cost_a);
		printf("cost_b %d\n", aux->cost_b);
		printf("total_cost %d\n", aux->total_cost);
		printf("cheapest %d\n", aux->cheapest);
		printf("next %ld\n", aux->next->num);
		printf("prev %ld\n", aux->prev->num);
		printf("-------------------------\n");
		aux = aux->next;
		if (aux == node)
			break;
	}
} */