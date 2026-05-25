/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 22:35:20 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/25 17:13:02 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_av_valid(char **av)
{
	int	i;
	int	j;
	if (!av || !*av)
		return (1);
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!is_digit(av[i][j]) || av[1] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_av(int ac, char **av)
{
	ft_putstr_fd(RED, 2);
	if (ac == 1)
	{
		ft_putstr_fd(ERR_MISS_ARGV, 2);
		ft_putstr_fd(RST, 2);
		return (1);
	}
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd(ERR_INVALID_NUM, 2);
		ft_putstr_fd(RST, 2);
		return (1);
	}
	if (is_av_valid(av) || ft_atoi(av[1]) == 0)
	{
		ft_putstr_fd(ERR_INVALID_ARGV, 2);
		ft_putstr_fd(RST, 2);
		return (1);
	}
	return (0);
}
