/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:44:38 by carmegon          #+#    #+#             */
/*   Updated: 2025/10/17 13:44:38 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

int	ft_digit_space(char c)
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

int ft_sign(char *str)
{
    int i;

    i = 0;
    if (!str[i])
        return (0);
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

int ft_no_repeat(char **list)
{
    int     i;
    int     j;

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

int is_order(char **list)
{
    int     i;
    int     j;

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
// Esta funcion es la primera de todas para unificar todos los argv en uno
char    *ft_one_argv(char **av)
{
    char    *res;
    int     i;

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

char    **ft_split_argv(int ac, char **av)
{
    char    *one_av;
    char    **list;

    if (ac < 2)
        return (NULL);
    one_av = ft_one_argv(av);
    list = ft_split(one_av, ' ');
    free(one_av);
    if (!list)
        ft_error();
    return (list);
}

int ft_is_valid(int ac, char **av)
{
    int     i;
    int     j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        if (av[i][j] == '\0')
            return (0);
        while (av[i][j])
        {
            if (ft_sign(av[i]))
                return (1);
            else if (ft_digit_space(av[i][j]))
                return (1);
            else if (ft_no_repeat(av))
                return (1);
            else if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void ft_parsing(int ac, char **av)
{
    if (ft_is_valid(ac, av))
        ft_error();
    else if (!is_order(av))
        exit(0);
}

int main(int ac, char **av)
{
    int     i;
    char    **res;
    //int     j;

    if (ac == 1)
        return (0);
    i = 1;
    while (av[i])
    {
        res = ft_split_argv(ac, av);
        ft_printf("%d\n", ft_atol(res[i]));
        i++;
    }
    free(res);
    return (0);
}
