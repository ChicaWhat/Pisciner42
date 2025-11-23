/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:47:17 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/23 22:58:00 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void	set_positions(t_node **stack_a)
{
	t_node	*aux;
	int		i;

	if (!(*stack_a))
		return ;
	aux = (*stack_a);
	i = 1;
	while (1)
	{
		aux->pos = i;
		aux->cheapest = 0;
		aux->total_cost = 0;
		aux = aux->next;
		i++;
		if (aux == (*stack_a))
			return ;
	}
}

