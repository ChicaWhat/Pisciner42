/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:46:55 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/26 18:05:03 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_top(unsigned int num)
{
	unsigned int	printed_bytes;
	unsigned int	d;

	printed_bytes = 0;
	d = num;
	if (num >= 16)
	{
		printed_bytes += ft_print_hex_top(num / 16);
	}
	d = num % 16;
	if (d >= 0 && d <= 9)
	{
		d = d + '0';
		printed_bytes += write(1, &d, 1);
	}
	else if (d >= 10 && d < 16)
	{
		d = 'A' + (d - 10);
		printed_bytes += write(1, &d, 1);
	}
	return (printed_bytes);
}
