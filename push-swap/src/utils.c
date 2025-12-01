/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:47:17 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/01 21:26:59 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Function to update positions and 
//reset total_cost and cheapest values to 0
void	set_positions(t_node **stack_a)
{
	t_node	*aux;
	int		i;

	if (!stack_a || !(*stack_a))
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

//--- Function to find the smallest node ---//
t_node	*find_min_node(t_node **stack_a)
{
	t_node	*aux;
	t_node	*min_node;
	int		index_winner;

	aux = (*stack_a);
	index_winner = INT_MAX;
	while (1)
	{
		if (aux->index < index_winner)
		{
			index_winner = aux->index;
			min_node = aux;
		}
		aux = aux->next;
		if (aux == (*stack_a))
			break ;
	}
	return (min_node);
}

// Function to transform char* to long int and 
// check that no argument exceeds INT_MIN or INT_MAX
long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	while (str[i] < 33)
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	n = 0;
	while (str[i])
	{
		if (n > INT_MAX || n < INT_MIN)
			return (LONG_MAX);
		else if (str[i] < '0' || str[i] > '9')
			return (n * sign);
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
