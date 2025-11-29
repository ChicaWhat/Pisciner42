/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:14:53 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/20 17:14:53 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"
// Stack A and stack B make rotate //
void	path1(t_node **stack_a, t_node **stack_b, t_node *cheapest)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		ft_rr(stack_a, stack_b);
		cheapest->cost_a--;
		cheapest->cost_b--;
		cheapest->total_cost -= 2;
	}
	while (cheapest->cost_a > 0)
	{
		ft_ra(stack_a);
		cheapest->cost_a--;
		cheapest->total_cost--;
	}
	while (cheapest->cost_b > 0)
	{
		ft_rb(stack_b);
		cheapest->cost_b--;
		cheapest->total_cost--;
	}
}
// Stack A and stack b make reverse rotate //
void	path2(t_node **stack_a, t_node **stack_b, t_node *cheapest)
{
    while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
    {
		ft_rrr(stack_a, stack_b);
		cheapest->cost_a++;
		cheapest->cost_b++;
		cheapest->total_cost -= 2;
	}
	while (cheapest->cost_a < 0)
	{
		ft_rra(stack_a);
		cheapest->cost_a++;
		cheapest->total_cost--;
	}
	while (cheapest->cost_b < 0)
	{
		ft_rrb(stack_b);
		cheapest->cost_b++;
		cheapest->total_cost--;
	}
}
// Stack A makes rotate and stack B makes reverse rotate //
void	path3(t_node **stack_a, t_node **stack_b, t_node *cheapest)
{
	while (cheapest->cost_a > 0)
	{
		ft_ra(stack_a);
		cheapest->cost_a--;
		cheapest->total_cost--;
	}
	while (cheapest->cost_b < 0)
	{
		ft_rrb(stack_b);
		cheapest->cost_b++;
		cheapest->total_cost--;
	}
}
// Stack A makes reverse rotate and stack B makes rotate //
void	path4(t_node **stack_a, t_node **stack_b, t_node *cheapest)
{
	while (cheapest->cost_a < 0)
	{
		ft_rra(stack_a);
		cheapest->cost_a++;
		cheapest->total_cost--;
	}
	while (cheapest->cost_b > 0)
	{
		ft_rb(stack_b);
		cheapest->cost_b--;
		cheapest->total_cost--;
	}
}
// Function to generate all scenarios //
void	four_possibilities(t_node **stack_a, t_node **stack_b, t_node **cheapest)
{
	if ((*cheapest)->cost_a >= 0 && (*cheapest)->cost_b >= 0)
		path1(stack_a, stack_b, (*cheapest));
	else if ((*cheapest)->cost_a <= 0 && (*cheapest)->cost_b < 0)
		path2(stack_a, stack_b, (*cheapest));
	else if ((*cheapest)->cost_a >= 0 && (*cheapest)->cost_b < 0)
		path3(stack_a, stack_b, (*cheapest));
	else if ((*cheapest)->cost_a < 0 && (*cheapest)->cost_b >= 0)
		path4(stack_a, stack_b, (*cheapest));
	if ((*cheapest)->total_cost == 0)
		ft_pa(stack_b, stack_a);
}
