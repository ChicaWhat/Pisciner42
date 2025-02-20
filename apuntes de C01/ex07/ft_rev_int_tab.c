/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:08:35 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/10 15:52:05 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_rev_int_tab(int *tab, int size)
{
	int	aux;
	int     start;
	int	end;

	start = 0;
	end = size - 1;
	while (tab[start] < tab[end])
	{
		aux = tab[start];
		tab[start] = tab[end];
		tab[end] = aux;
		start++;
		end--;
	}	
}

int	main()
{
	int	tab[3];
	int j;
	int i;
	int k;
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	ft_rev_int_tab(tab, 3);
	j = tab[0] + '0';
	i = tab[1] + '0';
	k = tab[2] + '0';
	write(1, &j, 1);
	write(1, &i, 1);
	write(1, &k, 1);
	return (0);
}
