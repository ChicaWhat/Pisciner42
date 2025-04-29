/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:52:14 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/28 12:05:31 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*aux;
	unsigned char		*cpy;

	aux = (const unsigned char *)src;
	cpy = (unsigned char *)dest;
	i = n - 1;
	if (!aux && !cpy)
		return (NULL);
	if (cpy > aux)
	{
		while (i > 0)
		{
			cpy[i] = aux[i];
			i--;
		}
	}
	else
		ft_memcpy(cpy, aux, n);
	return ((void *)dest);
}
