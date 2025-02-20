/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:27:48 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/07 11:57:00 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_writes(char n)
{
	write(1, &n, 1);
}

void	ft_print_comb(void)
{
	char	n1;
	char	n2;
	char	n3;

	n1 = '0';
	while (n1 <= '7')
	{
		n2 = n1 + 1;
		while (n2 <= '8')
		{
			n3 = n2 + 1;
			while (n3 <= '9')
			{
				ft_writes(n1);
				ft_writes(n2);
				ft_writes(n3);
				if (n1 != '7' || n2 != '8' || n3 != '9')
					write (1, ", ", 2);
				n3++;
			}
			n2++;
		}
		n1++;
	}
}

int	main()
{
	ft_print_comb();
	return (0);
}
