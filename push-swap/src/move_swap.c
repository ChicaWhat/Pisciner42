/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:35:02 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/06 17:35:02 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void    ft_swap(t_node **stack)
{
    t_node  *aux;

    //aux = (*stack)->prev->prev;
    (*stack) = (*stack)->next;
    if ((*stack)->next == (*stack)->prev)
        return;
    (*stack)->prev->prev->next = (*stack);
    (*stack)->next->prev = (*stack)->prev;
    aux = (*stack)->prev->prev;
    (*stack)->prev->prev = (*stack);
    (*stack)->prev->next = (*stack)->next;
    (*stack)->next = (*stack)->prev;
    (*stack)->prev = aux;
}




