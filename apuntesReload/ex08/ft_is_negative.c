/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:20:56 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/07 19:45:15 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char s)
{
	write(1, &s, 1);
}

void	ft_is_negative(int n)
{
	char sign;
	sign = 'P';

	if (n >= 0)
	{
		ft_putchar(sign);
	}
	else
	{
		sign = 'N';
		ft_putchar(sign);
	}
}

int	main()
{
	ft_is_negative(-5);
	return (0);
}
