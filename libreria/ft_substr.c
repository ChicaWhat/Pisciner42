/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:34:37 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/08 16:22:02 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	unsigned int	i;

	if (start > ft_strlen(s))
	{
		sub_s = ft_calloc(1, 1);
		printf("%p -> Direccion de cadena vacia", sub_s);
		return (sub_s);
	}
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub_s = (char *)malloc(len + 1 * sizeof(char));
	if (!sub_s)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		sub_s[i] = s[start];
		i++;
		start++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}


#include <stdio.h>
int	main(void)
{
	char	s[] = "Hola mundo cruel peperoni";
	char	*sub_s = ft_substr(s, 36, 3);
	printf("%s\n", sub_s);
	free(sub_s);
	return (0);
}
