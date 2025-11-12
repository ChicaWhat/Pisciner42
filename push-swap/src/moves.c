/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
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

