/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:54:56 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/01 23:05:07 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	total_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*a;
	t_node	*b;

	a = (*stack_a);
	b = (*stack_b);
	while (1)
	{
		if (a->index == b->target)
		{
			calculate_combined_cost(&a, &b);
			b->cost_a = a->cost_a;
			break ;
		}
		a = a->next;
		if (a == (*stack_a))
			break ;
	}
}

void	set_total_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*b;

	if (!stack_b || !(*stack_b))
		return ;
	b = (*stack_b);
	while (1)
	{
		total_cost(stack_a, &b);
		b = b->next;
		if (b == (*stack_b))
			break ;
	}
}

void	calculate_combined_cost(t_node **a, t_node **b)
{
	if ((*a)->index == (*b)->target)
	{
		if (((*a)->cost_a > 0 && (*b)->cost_b > 0)
			|| ((*a)->cost_a < 0 && (*b)->cost_b < 0))
		{
			if (abs_cost((*a)->cost_a) > abs_cost((*b)->cost_b))
				(*b)->total_cost = abs_cost((*a)->cost_a);
			else
				(*b)->total_cost = abs_cost((*b)->cost_b);
		}
		else
			(*b)->total_cost = abs_cost((*a)->cost_a) + abs_cost((*b)->cost_b);
	}
}

// --- Finds the cheapest node in stack B --- //
t_node	*cheapest_node(t_node **stack_b)
{
	t_node	*aux;
	t_node	*best_cheapest;

	aux = (*stack_b);
	best_cheapest = (*stack_b);
	while (1)
	{
		if (aux->total_cost < best_cheapest->total_cost)
			best_cheapest = aux;
		aux = aux->next;
		if (aux == (*stack_b))
			break ;
	}
	best_cheapest->cheapest = 1;
	return (best_cheapest);
}

/* void	total_cost(t_node **stack_a, t_node **stack_b)
{
	t_node	*a;
	t_node	*b;

	a = (*stack_a);
	b = (*stack_b);
	while (1)
	{
		if (a->index == b->target)
		{
			if ((a->cost_a > 0 && b->cost_b > 0)
				|| (a->cost_a < 0 && b->cost_b < 0))
			{
				if (abs_cost(a->cost_a) > abs_cost(b->cost_b))
					b->total_cost = abs_cost(a->cost_a);
				else
					b->total_cost = abs_cost(b->cost_b);
			}
			else
				b->total_cost = abs_cost(a->cost_a) + abs_cost(b->cost_b);
			b->cost_a = a->cost_a;
			break ;
		}
		a = a->next;
		if (a == (*stack_a))
			break ;
	}
} */