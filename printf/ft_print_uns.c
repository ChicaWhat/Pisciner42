/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:08:01 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/26 17:18:31 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uns(unsigned int num)
{
	int					printed_bytes;
	char				d;
	unsigned long int	n;

	n = num;
	printed_bytes = 0;
	if (num >= 10)
	{
		printed_bytes += ft_print_nbr(num / 10);
	}
	d = num % 10 + '0';
	printed_bytes += write(1, &d, 1);
	return (printed_bytes);
}
