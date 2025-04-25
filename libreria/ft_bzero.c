/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:36:10 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/25 15:22:22 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	unsigned char	*aux;

	i = 0;
	aux = (unsigned char *)s;
	while (i < n)
	{
		aux[i] = '\0';
		i++;
	}
}
