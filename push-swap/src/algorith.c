/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorith.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:19:36 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/18 06:10:02 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

// -- Order 2 nodes -- //
void    order_two_nodes(t_node **stack)
{
    if ((*stack)->num > (*stack)->next->num)
        ft_sa(stack);
}

// -- Order 3 nodes -- //
void    order_three_nodes(t_node **stack_a)
{
    int a;
    int b;
    int c;

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

// -- Function that order 3 nodes or less -- //
void    order_nodes(t_node **stack_a, int size)
{
    if (size == 1)
        return;
    else if (size == 2)
        order_two_nodes(stack_a);
    else if (size == 3)
        order_three_nodes(stack_a);
}

void	move_stacks(t_node **stack_a, t_node **stack_b, int size)
{
	int		size_b;
	
	size = stack_size(stack_a);
	while (size > 3)
	{
		if ((*stack_a)->index < (*stack_a)->size - 3)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		size = stack_size(stack_a);
		size_b = stack_size(stack_b);
		set_positions(stack_a);
		printf("coño\n");
		set_positions(stack_b);
		printf("puto\n");
	}
	order_three_nodes(stack_a);
}

void	cost_a(t_node **stack_a)
{
	t_node *aux;
	int		size;
	
	size = stack_size(stack_a);
	aux = (*stack_a);
	while (1)
	{
		if (aux->pos <= size / 2)
			aux->cost_a = aux->pos - 1;
		else
			aux->cost_a = (size - aux->pos) + 1;
		aux = aux->next;
		if (aux == (*stack_a))
			return ;
	}
}

void	cost_b(t_node **stack_b)
{
	t_node *aux;
	int		size;
	
	size = stack_size(stack_b);
	aux = (*stack_b);
	while (1)
	{
		if (aux->pos <= size / 2)
			aux->cost_b = aux->pos - 1;
		else
			aux->cost_b = (size - aux->pos) + 1;
		aux = aux->next;
		if (aux == (*stack_b))
			return ;
	}
}

void	put_total_cost(t_node **a, t_node **b)
{
	t_node	*aux_b;
	t_node	*aux_a;
	int		best_index;

	aux_b = (*b);
	while (1)
	{
		best_index = 9999;
		aux_a = (*a);
		while (1)
		{
			if ((aux_a->index > aux_b->index) && (best_index > aux_a->index))
				aux_b->total_cost = aux_a->cost_a + aux_b->cost_b;
			aux_a = aux_a->next;
			if (aux_a == (*a))
				break ;
		}
		aux_b = aux_b->next;
		if (aux_b == (*b))
			break ;
	}
}
