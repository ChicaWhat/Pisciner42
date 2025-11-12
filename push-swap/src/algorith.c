/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorith.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:19:36 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/12 18:19:36 by carmegon         ###   ########.fr       */
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
    int *a;
    int *b;
    int *c;
    
}