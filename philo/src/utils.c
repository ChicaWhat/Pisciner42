/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 22:33:48 by carmegon          #+#    #+#             */
/*   Updated: 2026/04/08 22:37:02 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_digit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(char *s)
{
	long	result;
	int		i;

	i = 0;
	result = 0;
	while (s[i] && is_digit(s[i]))
	{
		result = (result * 10) + (s[i] - '0');
		if (result > 2147483647)
			return (-1);
		i++;
	}
	return ((int)result);
}
