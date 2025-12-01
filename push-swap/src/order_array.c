/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:28:12 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/01 21:23:59 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*push_swap(char **av)
{
	t_node	*stack_a;
	int		size;
	long	*list_num;

	stack_a = init_stack(av);
	if (!stack_a)
	{
		free(stack_a);
		return (NULL);
	}
	size = stack_size(&stack_a);
	list_num = ft_convert_to_long_array(av, size);
	list_num = ft_order_long(list_num, size);
	ft_index_nodes(list_num, size, &stack_a);
	set_positions(&stack_a);
	order_nodes(&stack_a, size);
	free(list_num);
	return (stack_a);
}

//--- Function to sort the long array ---//
long	*ft_order_long(long *list_num, int size)
{
	int		i;
	int		j;
	long	aux;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (list_num[i] > list_num[j])
			{
				aux = list_num[i];
				list_num[i] = list_num[j];
				list_num[j] = aux;
			}
			else
				j++;
		}
		i++;
	}
	return (list_num);
}

//--- Function to add the sorted indexes to the nodes ---//
void	ft_index_nodes(long *list_num, int size, t_node **stack)
{
	int		i;
	t_node	*aux;

	i = 0;
	while (i < size)
	{
		aux = (*stack);
		while (1)
		{
			if (list_num[i] == aux->num)
			{
				aux->index = i;
				break ;
			}
			aux = aux->next;
			if (aux == (*stack))
				break ;
		}
		i++;
	}
}

//--- Function to count the size of the stack ---//
int	stack_size(t_node **stack)
{
	t_node	*aux;
	int		count;

	if (!stack || !(*stack))
		return (0);
	count = 0;
	aux = (*stack);
	while (1)
	{
		count++;
		aux = aux->next;
		if (aux == (*stack))
			break ;
	}
	return (count);
}
