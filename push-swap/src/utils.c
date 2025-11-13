/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:47:17 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/13 20:17:14 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void	set_positions(t_node **stack_a)
{
	t_node	*aux;
	int		i;

	aux = (*stack_a);
	i = 1;
	while (1)
	{
		if (aux->pos == 0)
		{
			aux->pos = i;
			i++;
		}
		if (aux->next == (*stack_a))
			break;
		aux = aux->next;
	}
}