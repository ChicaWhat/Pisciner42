/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:11:16 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/25 14:58:51 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	unsigned char	*aux;

	aux = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		aux[i] = c;
		i++;
	}
	s = (void *)aux;
	return (s);
}
