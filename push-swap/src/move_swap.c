/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:35:02 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/01 21:46:11 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// --- move swap --- //
void	ft_swap(t_node **stack)
{
	t_node	*aux;

	(*stack) = (*stack)->next;
	if ((*stack)->next == (*stack)->prev)
		return ;
	(*stack)->prev->prev->next = (*stack);
	(*stack)->next->prev = (*stack)->prev;
	aux = (*stack)->prev->prev;
	(*stack)->prev->prev = (*stack);
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = aux;
}

// --- move sa --- //
void	ft_sa(t_node **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

// --- move sb --- //
void	ft_sb(t_node **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

// --- move ss --- //
void	ft_ss(t_node **a, t_node **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
