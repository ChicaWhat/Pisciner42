/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:02:41 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/01 21:20:35 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// --- reverse rotate a --- //
void	ft_rra(t_node **a)
{
	(*a) = (*a)->prev;
	ft_printf("rra\n");
}

// --- reverse rotate b --- //
void	ft_rrb(t_node **b)
{
	(*b) = (*b)->prev;
	ft_printf("rrb\n");
}

// --- reverse rotate rotate --- //
void	ft_rrr(t_node **a, t_node **b)
{
	(*a) = (*a)->prev;
	(*b) = (*b)->prev;
	ft_printf("rrr\n");
}
