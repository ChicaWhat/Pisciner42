/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sort1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:47:46 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/01 22:09:52 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// -- Order 2 nodes -- //
void	order_two_nodes(t_node **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		ft_sa(stack);
}

// -- Order 3 nodes -- //
void	order_three_nodes(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->num;
	b = (*stack_a)->next->num;
	c = (*stack_a)->next->next->num;
	if (a > b && b < c && c > a)
		ft_sa(stack_a);
	else if (a > b && b > c && c < a)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
	}
	else if (a < b && b > c && c > a)
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
	else if (a > b && b < c && c < a)
		ft_ra(stack_a);
	else if (a < b && b > c && c < a)
		ft_rra(stack_a);
	set_positions(stack_a);
}

// -- Order 5 nodes -- //
void	order_five_nodes(t_node **stack_a, t_node **stack_b, int size)
{
	while (size > 3)
	{
		if ((*stack_a)->index < 2)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		size = stack_size(stack_a);
	}
	if ((*stack_b)->num < (*stack_b)->next->num)
		ft_sb(stack_b);
	order_three_nodes(stack_a);
	ft_pa(stack_b, stack_a);
	ft_pa(stack_b, stack_a);
}

// -- Function that order 2, 3, 5 or more nodes -- //
void	order_nodes(t_node **stack_a, int size)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (size == 1)
		return ;
	else if (size == 2)
		order_two_nodes(stack_a);
	else if (size == 3)
		order_three_nodes(stack_a);
	else if (size == 5)
		order_five_nodes(stack_a, &stack_b, size);
	else
		move_stacks(stack_a, &stack_b, size);
}

// Moves nodes from A to B, leaving 3 in A, then applies sorting algorithm
void	move_stacks(t_node **stack_a, t_node **stack_b, int size)
{
	int		total_size;

	total_size = size;
	while (total_size)
	{
		if ((*stack_a)->index < (total_size / 2) + 1)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		total_size--;
	}
	while (size > 3)
	{
		if ((*stack_a)->index < (*stack_a)->size - 3)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		size = stack_size(stack_a);
		set_positions(stack_a);
		set_positions(stack_b);
	}
	order_three_nodes(stack_a);
	make_sort(stack_a, stack_b, size);
}
