/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:44:38 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/26 19:45:49 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

//--- Funcion para detectar cualquier caracter que no sea numerico---//
int ft_digit_space(char c)
{
    if (c == '+' || c == '-')
        return (0);
    else if (c >= 48 && c < 58)
        return (0);
    else if (c == 32)
        return (0);
    else
        return (1);
}
//--- Funcion para comprobar si hay cualquier caracter no numerico al principio y entre medias del av---//
int ft_sign(char *str)
{
    int i;

    i = 0;
    if (!str[i] || str[i] == '\0')
        return (1);
    while (str[i])
    {
        if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
            return (1);
        else if (ft_digit_space(str[i]))
            return (1);
        else if (ft_isdigit(str[i]) && (str[i + 1] == '+' || str[i + 1] == '-'))
            return (1);
        i++;
    }
    return (0);
}
//--- Función que comprueba si pasan av que no estén repetidos ---//
int ft_no_repeat(char **list)
{
    int i;
    int j;

    i = 0;
    while (list[i])
    {
        j = i + 1;
        while (list[j])
        {
            if (ft_atol(list[i]) != ft_atol(list[j]))
                j++;
            else
                return (1);
        }
        i++;
    }
    return (0);
}
//--- Función que comprueba si los av ya están ordenados ---//
int is_order(char **list)
{
    int i;
    int j;

    i = 0;
    while ((list[i]))
    {
        j = i + 1;
        while ((list[j]))
        {
            if (ft_atol(list[i]) < ft_atol(list[j]))
                j++;
            else
                return (1);
        }
        i++;
    }
    return (0);
}
//--- Función para transformar los char* a long int y comprobar que no me pasan un av que sobrepase los valores de INT_MIN o INT_MAX ---//
long ft_atol(char *str)
{
    int i;
    int sign;
    long n;

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
// Función que unifica todos los **av en un único array ---//
char *ft_one_argv(char **av)
{
    char *res;
    int i;

    res = ft_calloc(1, sizeof(char));
    if (!res)
        return (NULL);
    i = 0;
    while (av[i])
    {
        res = ft_strjoin(res, av[i]);
        res = ft_strjoin(res, " ");
        if (!res)
        {
            free(res);
            ft_error();
        }
        i++;
    }
    return (res);
}
//--- Función para splitear el único av creado anteriormente ---//
char **ft_split_argv(char *one_av)
{
    char    **list;

    list = ft_split(one_av, ' ');
    if (!list)
    {
        free(one_av);
        ft_error();
    }
    free(one_av);
    return (list);
}
//--- Función para calcular el tamaño de la lista ---//
int list_size(char **list_num)
{
    int i;

    i = 0;
    while (list_num[i])
        i++;
    return (i);
}
//--- Función que transforma el char** en long* --//
long *ft_convert_to_long_array(char **list, int size)
{
    int     i;
    long    *long_array;
    
    i = 0;
    long_array = malloc(size * sizeof(long));
    if (!long_array)
    {
        ft_free_all(list, NULL, NULL);
        return (NULL);
    }
    while (i < size)
    {
        long_array[i] = ft_atol(list[i]);
        i++;
    }
    return (long_array);
}
//--- Función que comprueba de una llamada si el av pasado es válido ---//
int ft_is_valid(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        if (av[i][j] == '\0')
            return (1);
        while (av[i][j])
        {
            if (ft_sign(av[i]))
                return (1);
            else if (ft_digit_space(av[i][j]))
                return (1);
            else if (ft_no_repeat(av+1))
                return (1);
            else if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
//--- Función que complementa a ft_is_valid y completa el parseo ---//
void ft_parsing(int ac, char **av)
{
	if (ft_is_valid(ac, av))
		ft_error();
    if (!is_order(av))
        exit(0);
}
//--- Función que me printea toda la info que necesite de los nodos ---//
void	print_nodes(t_node *node)
{
    t_node  *aux;

	if (!node)
		return ;
	
    aux = node;
    while (1)
    {
        printf("nodo %ld\n", aux->num);
        printf("index %d\n", aux->index);
        printf("target %ld\n", aux->target);
        printf("posicion %d\n", aux->pos);
		printf("cost_a %d\n", aux->cost_a);
		printf("cost_b %d\n", aux->cost_b);
		printf("total_cost %d\n", aux->total_cost);
		printf("cheapest %d\n", aux->cheapest);
/*         printf("next %ld\n", aux->next->num);
        printf("prev %ld\n", aux->prev->num); */
        printf("-------------------------\n");
        aux = aux->next;
        if (aux == node)
            break;
    }
}

//! MAIN ORIGINAL
int main(int ac, char **av)
{
    t_node  *stack_a;

    if (ac == 1)
        return (0);
    ft_parsing(ac, av);
    stack_a = push_swap(av+1);
    if (!stack_a)
    {
        free(stack_a);
        return (1);
    }
/*     printf("Stack A:\n");
    print_nodes(stack_a);
	move_stacks(&stack_a, &stack_b, size);
    printf("Stack A:\n");
    print_nodes(stack_a);
    printf("Stack B:\n");
    print_nodes(stack_b);	 */
    //print_nodes(stack_a);
    free(stack_a);
    return (0);
}
