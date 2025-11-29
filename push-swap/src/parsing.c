/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:57:41 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/29 16:57:41 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

//--- Function to check in one call if the passed av is valid ---//
int	ft_is_valid(int ac, char **av)
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
//--- Function that complements ft_is_valid and completes parsing ---//
void	ft_parsing(int ac, char **av)
{
	if (ft_is_valid(ac, av))
		ft_error();
	if (!is_order(av))
		exit(0);
}
