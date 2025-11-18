/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:47:17 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/18 06:12:58 by carmegon         ###   ########.fr       */
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
		aux = aux->next;
		i++;
		if (aux == (*stack_a))
			return ;
	}
}

