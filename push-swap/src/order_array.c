/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:28:12 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/29 17:16:36 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

t_node	*push_swap(char **av)
{
	t_node	*stack_a;
	int		size;
	long	*list_num;
	//int		count;
	
	stack_a = init_stack(av);
	if (!stack_a)
	{
		free(stack_a);
		return (NULL);
	}
	size = count_stack(&stack_a);
	list_num = ft_convert_to_long_array(av, size);
	list_num = ft_order_long(list_num, size);
	ft_index_nodes(list_num, size, &stack_a);
	//count = stack_size(&stack_a);
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
				break;
			}
			aux = aux->next;
			if (aux == (*stack))
			break;
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
//--- Function to count the size of the stack ---//
/* int		count_stack(t_node **stack)
{
	int	count;
	t_node *aux;
	aux = (*stack);
	count = 0;
	while (1)
	{
		count++;
		aux = aux->next;
		if (aux == (*stack))
			break ;
	}
	return (count);
} */

//! COMPROBANDO SI ORDENA EL ARRAY DE LONG
/* int main(int ac, char **av)
{
    (void)ac;
    char    *one_av;
    char    **list;
    int     size;
    long    *list_num;
    t_node  *stack_a;
    long    *order;

    one_av = ft_one_argv(av+1);
    if (!one_av)
        return (0);
    list = ft_split_argv(one_av);
    if (!list)
        return (0);
    size = list_size(list);
    list_num = ft_convert_to_long_array(list, size);
    printf("Lista de números sin ordenar:");
    for (int i = 0; i < size; i++)
    {
        printf("%ld ", list_num[i]);
    }
    printf("\n");
    order = ft_order_long(list_num, size);
    printf("Lista de números ordenados:");
    for (int i = 0; i < size; i++)
    {
        printf("%ld ", order[i]);
    }
    printf("\n");
    stack_a = init_stack(av+1);
    if (!stack_a)
    {
        free(stack_a);
        return (1);
    }
    printf("Índices de los nodos: ");
    ft_index_nodes(list_num, size, &stack_a);
    print_nodes(stack_a);
    free(stack_a);
    return (0);
} */