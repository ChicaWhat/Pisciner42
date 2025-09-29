/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:05:48 by carmegon          #+#    #+#             */
/*   Updated: 2025/09/23 16:14:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_atoi(const char *nptr)
{
	int sign;
	int d;
	int result;

	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\r' || *nptr == '\f' || *nptr == '\v')
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= (-1);
		nptr++;
	}
	d = 0;
	result = 0;
	while (ft_isdigit(*nptr))
	{
		d = *nptr - '0';
		result = (result * 10) + d;
		nptr++;
	}
	return (sign * result);
}
