/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:46:30 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/24 22:42:27 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	imput;
	int	printed_bytes;
	int	i;

//	va_start(ap, format);

	printed_bytes = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		
		if != '%'
			putchat;
			printed_bytes++;
		else 
			escoger qué y como
			if 'c'
				putchar 
				printed_bytes++;
			if 's'
				putstr
				pb += los que haya impreso
				-----
				pb += putstr
			if 'd'
				putnbr
				pb += los que haya imprimido
			
		i++;
	}
	return (printed_bytes);
}


