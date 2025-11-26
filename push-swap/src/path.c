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
/* 	if (cheapest->total_cost == 0)
		ft_pa(stack_b, stack_a); */
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
/* 	if (cheapest->total_cost == 0)
		ft_pa(stack_b, stack_a); */
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
/* 	if (cheapest->total_cost == 0)
    	ft_pa(stack_b, stack_a); */
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
/* 	if (cheapest->total_cost == 0)
    	ft_pa(stack_b, stack_a); */
}
// Function to generate all scenarios //
void	four_possibilities(t_node **stack_a, t_node **stack_b, t_node **cheapest)
{
	 	printf("Stack A\n");
		print_nodes(*stack_a);
		printf("Stack B\n");
		print_nodes(*stack_b);
	if ((*cheapest)->cost_a >= 0 && (*cheapest)->cost_b >= 0)
	{
		path1(stack_a, stack_b, (*cheapest));
		printf("1\n");
	}
	else if ((*cheapest)->cost_a <= 0 && (*cheapest)->cost_b < 0)
	{
		path2(stack_a, stack_b, (*cheapest));
		printf("2\n");
	}
	else if ((*cheapest)->cost_a >= 0 && (*cheapest)->cost_b < 0)
	{
		path3(stack_a, stack_b, (*cheapest));
		printf("3\n");
	}
	else if ((*cheapest)->cost_a < 0 && (*cheapest)->cost_b >= 0)
	{
		path4(stack_a, stack_b, (*cheapest));
		printf("4\n");
	}
	if ((*cheapest)->total_cost == 0)
		ft_pa(stack_b, stack_a);
}
// 
void	make_sort(t_node **stack_a, t_node **stack_b, int size)
{
	//t_node	*aux;
	t_node	*cheapest;

	//aux = (*stack_b);
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

t_node	*find_min_node(t_node **stack_a)
{
	t_node	*aux;
	t_node	*min_node;
	int		index_winner;

	aux = (*stack_a);
	index_winner = INT_MAX;
	while (1)
	{
		if (aux->index < index_winner)
		{
			index_winner = aux->index;
			min_node = aux;
		}
		aux = aux->next;
		if (aux == (*stack_a))
		break;
	}
	return (min_node);
}
