/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:24:45 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/12 17:45:27 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	res;

	if (nb < 0)
		res = 0;

	i = 0;
	res = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			res = i;
		i++;
	}
	return (res);
}

int	main()
{
	printf("%d\n", ft_sqrt(3025));
	return (0);
}
