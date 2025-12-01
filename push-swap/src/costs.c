/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:52:32 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/01 22:20:23 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// --- Function that calculates the cost to move nodes in stack A --- //
void	cost_a(t_node **stack_a)
{
	t_node	*aux;
	int		size;

	size = stack_size(stack_a);
	aux = (*stack_a);
	while (1)
	{
		if (aux->pos <= (size + 1) / 2)
			aux->cost_a = aux->pos - 1;
		else
		{
			aux->cost_a = (aux->pos - size) - 1;
		}
		aux = aux->next;
		if (aux == (*stack_a))
			return ;
	}
}

// --- Function that calculates the cost to move nodes in stack B --- //
void	cost_b(t_node **stack_b)
{
	t_node	*aux;
	int		size;

	if (!stack_b || !(*stack_b))
		return ;
	size = stack_size(stack_b);
	aux = (*stack_b);
	while (1)
	{
		if (aux->pos <= (size + 1) / 2)
			aux->cost_b = aux->pos - 1;
		else
			aux->cost_b = (aux->pos - size) - 1;
		aux = aux->next;
		if (aux == (*stack_b))
			return ;
	}
}

// -- Function that turns the negative values to positive values --//
int	abs_cost(int cost)
{
	if (cost < 0)
		cost = -cost;
	return (cost);
}
