/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:55:23 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/01 21:45:57 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// --- rotate a ---//
void	ft_ra(t_node **a)
{
	(*a) = (*a)->next;
	ft_printf("ra\n");
}

// --- rotate b ---//
void	ft_rb(t_node **b)
{
	(*b) = (*b)->next;
	ft_printf("rb\n");
}

// --- rotate rotate ---//
void	ft_rr(t_node **a, t_node **b)
{
	(*a) = (*a)->next;
	(*b) = (*b)->next;
	ft_printf("rr\n");
}
