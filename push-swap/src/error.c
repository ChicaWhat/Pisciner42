/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:44:56 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/28 16:17:17 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../push-swap.h"
//--- Función para escribir "Error" por pantalla ---//
void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
//--- Función para liberar dobles arrays, arrays y nodos cuando sea necesario ---//
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
