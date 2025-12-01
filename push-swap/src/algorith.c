/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorith.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:19:36 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/01 22:07:37 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// --- Finds and sets the target index in stack A for a node in stack B --- //
void	set_target(t_node **a, t_node **stack_b)
{
	t_node	*aux_a;
	int		best_index;
	t_node	*target_node;

	aux_a = (*a);
	best_index = INT_MAX;
	target_node = NULL;
	while (1)
	{
		if ((aux_a->index > (*stack_b)->index) && (best_index > aux_a->index))
		{
			best_index = aux_a->index;
			target_node = aux_a;
			(*stack_b)->target = target_node->index;
		}
		aux_a = aux_a->next;
		if (aux_a == (*a))
			break ;
	}
	if (!target_node)
	{
		target_node = find_min_node(a);
		(*stack_b)->target = target_node->index;
	}
}

// Sets target indices in stack A for all nodes in stack B
void	set_all_targets(t_node **stack_a, t_node **stack_b)
{
	t_node	*b;

	if (!stack_b || !(*stack_b))
		return ;
	b = (*stack_b);
	while (1)
	{
		set_target(stack_a, &b);
		b = b->next;
		if (b == (*stack_b))
			break ;
	}
}
