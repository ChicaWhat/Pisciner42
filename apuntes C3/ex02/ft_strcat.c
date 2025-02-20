/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 08:58:19 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/18 16:21:53 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	x;

	i = 0;
	while (dest[i] != '\0')
	{
		write(1, &dest[i], 1);
		i++;
	}

	x = 0;
	while (src[x] != '\0')
	{
		dest[i] = src[x];
		write(1, &src[x], 1);
		x++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main()
{
	char	dest[10] = "hola ";
	char	*src = "mundo";
	ft_strcat(dest, src);
	return (0);
}
