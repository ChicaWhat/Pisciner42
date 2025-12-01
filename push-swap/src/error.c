/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:44:56 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/01 21:18:25 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//--- Function to write "Error" to the screen ---//
void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

//--- Function to free double arrays, arrays, and nodes ---//
void	*ft_free_all(char **list, char *str, t_node **node)
{
	int	i;

	if (list)
	{
		i = 0;
		while (list[i])
		{
			free(list[i]);
			i++;
		}
		free(list);
	}
	if (str)
		free(str);
	if (node)
		free ((*node));
	return (NULL);
}

//--- Function to free the entire stack, node by node ---//
void	free_circular_list(t_node **stack)
{
	t_node	*next;
	t_node	*current;

	if (!stack || !(*stack))
		return ;
	current = (*stack)->next;
	while (current != (*stack))
	{
		next = current->next;
		free(current);
		current = next;
	}
	free ((*stack));
	(*stack) = NULL;
}
