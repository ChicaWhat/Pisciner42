/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:46:30 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/26 18:05:34 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_specifier(char specifier, va_list input)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (specifier == 'c')
		printed_bytes += ft_print_char(va_arg(input, int));
	else if (specifier == 's')
		printed_bytes += ft_print_str(va_arg(input, char *));
	else if (specifier == 'i')
		printed_bytes += ft_print_nbr(va_arg(input, int));
	else if (specifier == 'd')
		printed_bytes += ft_print_nbr(va_arg(input, int));
	else if (specifier == 'u')
		printed_bytes += ft_print_uns(va_arg(input, unsigned int));
	else if (specifier == '%')
		printed_bytes += ft_print_char(va_arg(input, int));
	else if (specifier == 'X')
		printed_bytes += ft_print_hex_top(va_arg(input, unsigned int));
	else if (specifier == 'x')
		printed_bytes += ft_print_hex_bottom(va_arg(input, unsigned int));
	else if (specifier == 'p')
		printed_bytes += ft_print_ptr(va_arg(input, void *));
	return (printed_bytes);
}

int	ft_printf(char const *chain, ...)
{
	va_list	input;
	int		printed_bytes;
	int		i;

	va_start(input, chain);
	printed_bytes = 0;
	i = 0;
	while (chain[i] != '\0')
	{
		if (chain[i] == '%')
		{
			i++;
			printed_bytes += ft_print_specifier(chain[i], input);
		}
		else
		{
			ft_print_char(chain[i]);
			printed_bytes++;
		}
		i++;
	}
	va_end(input);
	return (printed_bytes);
}
