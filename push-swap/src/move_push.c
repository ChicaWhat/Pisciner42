/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:55:19 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/12 19:55:19 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

// --- push movements --- //
void    ft_push(t_node **stack_src, t_node **stack_dest)
{
    t_node  *aux;

    aux = (*stack_src);
    if ((*stack_src)->next == (*stack_src))
        (*stack_src) = NULL;
    else
    {
        (*stack_src)->prev->next = (*stack_src)->next;
        (*stack_src)->next->prev = (*stack_src)->prev;
        (*stack_src) = (*stack_src)->next;
    }

    if ((*stack_dest) == NULL)
    {
        (*stack_dest) = aux;
        (*stack_dest)->next = (*stack_dest);
        (*stack_dest)->prev = (*stack_dest);
        return;
    }
    aux->next = (*stack_dest);
    aux->prev = (*stack_dest)->prev;
    (*stack_dest)->prev = aux;
    aux->prev->next = aux;
    (*stack_dest) = aux;
}

// --- pa (from b to a)--- //
void    ft_pa(t_node **b, t_node **a)
{
    if (!b)
        return;
    ft_push(b, a);
    ft_printf("pa\n");
}

// --- pb (from a to b)--- //
void    ft_pb(t_node **a, t_node **b)
{
    ft_push(a, b);
    ft_printf("pb\n");
}