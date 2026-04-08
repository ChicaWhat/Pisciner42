/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 22:35:20 by carmegon          #+#    #+#             */
/*   Updated: 2026/04/08 22:36:54 by carmegon         ###   ########.fr       */
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
			if (!is_digit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_av(int ac, char **av)
{
	if (ac == 1)
	{
		write(2, "Error: missing arguments\n", 26);
		return (1);
	}
	if (ac < 5 || ac > 6)
	{
		write(2, "Error: invalid numbers of arguments\n", 37);
		return (1);
	}
	if (is_av_valid(av))
	{
		write(2, "Error: invalid arguments\n", 26);
		return (1);
	}
	return (0);
}
