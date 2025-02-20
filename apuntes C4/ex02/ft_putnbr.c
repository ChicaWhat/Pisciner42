/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:31:17 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/20 18:03:06 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long n = nb;
	int	div;
	int	digit;

	div = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n / div >= 10)
	{
		div = div * 10;
	}
	while (div > 0 )
	{
		digit = n / div;
		write(1, &digit, 1);
		n = - (digit * div);
		div = div / 10;
	}
}

int	main()
{
	int n = -6446;
	char j;
	j = ft_putnbr(n) + '0';
	return (0);
}
