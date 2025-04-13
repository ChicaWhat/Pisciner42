/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:49:18 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/10 17:51:42 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	if (nb == 0)
		result = 1;
	else if (nb < 0)
		result = 0;
	else
		result = ft_recursive_factorial(nb - 1) * nb;
	return (result);
}

int	main()
{
	printf("%d\n", ft_recurive_factorial(5));
	return (0);
}
