/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:48:23 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/04 21:23:54 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;
	size_t		i;
	int		res;

	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	if (n == 0)
		res = 0;
	i = 0;
	while (i < n)
	{
		if (cast_s1[i] != cast_s2[i])
			res = (cast_s1[i] - cast_s2[i]);
		else
			res = 0;
		i++;
	}
	return (res);
}
