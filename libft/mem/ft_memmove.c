/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:52:14 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/13 10:06:56 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src_m;
	unsigned char		*dst_m;

	src_m = (const unsigned char *)src;
	dst_m = (unsigned char *)dest;
	i = n;
	if (!src_m && !dst_m)
		return (NULL);
	if (dst_m > src_m)
	{
		while (i > 0)
		{
			i--;
			dst_m[i] = src_m[i];
		}
	}
	else
		ft_memcpy(dst_m, src_m, i);
	return ((void *)dest);
}

/* int	main(void)
{
        char d[] = "Hola buenos dias";
        const char f[] = "Que tal estamos mi gente";
        printf("%s\n", (char *)ft_memmove(d+3, f+2, 5));
        return (0);
}  */