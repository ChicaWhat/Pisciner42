/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:05:07 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/28 10:20:05 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long long int			cst;
	int					printed_bytes;

	printed_bytes = 0;
	cst = (unsigned long long int)ptr;
	if (!cst)
		printed_bytes += write(1, "(nil)", 5);
	else
	{
		printed_bytes += write(1, "0x", 2);
		printed_bytes += ft_print_hex_bottom(cst);
	}
	return (printed_bytes);
}
