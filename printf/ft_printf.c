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

int	ft_printf(char const *chain, ...)
{
	va_list	imput;
	int	printed_bytes;
	int	i;

	va_start(imput, chain);

	printed_bytes = 0;
	i = 0;
	while (chain[i] != '\0')
	{
		if (chain[i] == '%')
		{
			i++;
			printed_bytes += print_specifier(chain[i], imput);
		}
		else
		{
			print_char(chain[i]);
			printed_bytes++;
		}
		i++;
	}
	va_end(imput);
	return (printed_bytes);
}

int	print_specifier(char specifier, va_list imput)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (specifier == 'c')
		printed_bytes += print_char(va_arg(imput, int));
	else if (specifier == 's')
		printed_bytes += print_str(va_arg(imput, char *));
	else if (specifier == 'i')
		printed_bytes += print_nbr(va_arg(imput, int));
	return(printed_bytes);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

char	print_str(char *str)
{
	int	i;

/* 	if (str == NULL)
		return (write(1, "NULL", 4)); */
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_nbr(int num)
{
	int	d;

	if (num == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
/* 	if (num >= 0 && num <= 9)
	{
		num = num + '0';
		write(1, &num, 1);
	} */
	if (num >= 10)
	{
		print_nbr(num / 10);
	}
	d = num % 10 + '0';
	write(1, &d, 1);
}
