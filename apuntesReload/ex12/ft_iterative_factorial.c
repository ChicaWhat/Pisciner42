/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:46:40 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/10 16:49:08 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	i;

	if (nb == 0)
	{
		result = 1;
	}
	else if (nb < 0)
	{
		result = 0;
	}
	else
	{
		result = nb;
		i = 1;
		while (i < nb)
		{
		result = result * i;
		// result *= i;
		i++;
		}
	}
	return (result);
}

int	main()
{
	printf("%d\n", ft_iterative_factorial(5));
	return (0);
}
