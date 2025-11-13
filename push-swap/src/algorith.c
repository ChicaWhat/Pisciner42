/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorith.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:19:36 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/13 11:59:54 by carmegon         ###   ########.fr       */
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

    a = (*stack_a)->index;
    b = (*stack_a)->next->index;
    c = (*stack_a)->next->next->index;

    if (a == 1 && b == 0 && c == 2)
        ft_sa(stack_a);
    else if (a == 2 && b == 1 && c == 0)
    {
        ft_ra(stack_a);
        ft_sa(stack_a);
    }
    else if (a == 0 && b == 2 && c == 1)
    {
        ft_rra(stack_a);
        ft_sa(stack_a);
    }
    else if (a == 2 && b == 0 && c == 1)
        ft_ra(stack_a);
    else if (a == 1 && b == 2 && c == 0)
        ft_rra(stack_a);
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


