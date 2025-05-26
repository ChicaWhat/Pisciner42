/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:39:50 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/26 17:07:00 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int num)
{
	char	d;
	int		printed_bytes;

	printed_bytes = 0;
	d = num;
	if (num == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		printed_bytes += write(1, "-", 1);
		num *= -1;
	}
	if (num >= 10)
	{
		printed_bytes += ft_print_nbr(num / 10);
	}
	d = num % 10 + '0';
	printed_bytes += write(1, &d, 1);
	return (printed_bytes);
}
