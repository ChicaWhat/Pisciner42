/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:05:58 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/30 22:48:08 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_isspace(char c)
{
	if ((c >= 7 && c <= 13) || c == 32)
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
	is_valid(&str[i]);
	if (str[i] == '.')
		i++;
	num += ft_double(&str[i]);
	return (num * sign);
}

void	is_valid(char *str)
{
	int	i;

	i = 0;
	if ((str[i] < '0' || str[i] > '9'))
	{
		if (str[i] != '.' && str[i] != '\0')
			ft_error_av();
	}
}
