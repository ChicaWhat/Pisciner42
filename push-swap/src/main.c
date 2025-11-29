/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:44:38 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/29 16:58:58 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	
	if (ac == 1)
	return (0);
	ft_parsing(ac, av);
	stack_a = push_swap(av+1);
	if (!stack_a)
	return (1);
	free_circular_list(&stack_a);
	return (0);
}
//! --- Función que unifica todos los **av en un único array ---//
/* char	*ft_one_argv(char **av)
{
	char	*res;
	char	*temp;
	int		i;

	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (av[i])
	{
		res = ft_strjoin(res, av[i]);
		res = ft_strjoin(res, " ");
		if (!res)
		{
			ft_free_all(NULL, res, NULL);
			//free(res);
			ft_error();
		}
		i++;
	}
	return (res);
} */
//--- Function to print all the information I need from the nodes ---//
void	print_nodes(t_node *node)
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
}