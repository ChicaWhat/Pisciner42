/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:25:30 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/19 02:36:18 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}

	x = 0;
	while (src[x] != '\0' && x < nb)
	{
		dest[i] = src[x];
		x++;
		i++;
	}

	return (dest);
}

int main()
{
        char dest[13] = "hola ";
        char *src = "adios";
        ft_strncat(dest, src, 14);
        return (0);
}
