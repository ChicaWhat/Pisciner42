/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:05:58 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/30 20:06:27 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_isspace(char c)
{
	if (c < 33)
		return (1);
	return (0);
}

double	ft_double(char *str)
{
	double	div;
	int		i;
	double	num;
	double	digit;

	i = 0;
	num = 0.0;
	digit = 0;
	div = 1.0;
	while (ft_isdigit(str[i]))
	{
		div = div * 10;
		digit = str[i] - '0';
		num = num + (digit / div);
		i++;
	}
	return (num);
}

double	ft_atod(char *str)
{
	double	num;
	int		i;
	int		sign;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	num = 0.0;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	num += ft_double(&str[i]);
	return (num * sign);
}