/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:18:48 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/29 17:18:48 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

//--- Function to sort ---//
void	make_sort(t_node **stack_a, t_node **stack_b, int size)
{
	t_node	*cheapest;

	while ((*stack_b) != NULL)
	{
		set_positions(stack_a);
		set_positions(stack_b);
		cost_a(stack_a);
		cost_b(stack_b);
		set_all_targets(stack_a, stack_b);
		set_total_cost(stack_a, stack_b);
		cheapest = cheapest_node(stack_b);
		four_possibilities(stack_a, stack_b, &cheapest);
	}
	last_moves(stack_a, size);
}
//--- Function to make the final moves ---//
void	last_moves(t_node **stack_a, int size)
{
	t_node	*aux;
	int		flag;

	aux = find_min_node(stack_a);
	if (!aux)
		return ;
	if (aux->pos < (size + 1) / 2)
		flag = 1;
	else
		flag = 0;
	while ((*stack_a) != aux)
	{
		if (flag)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}
