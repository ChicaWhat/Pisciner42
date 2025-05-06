/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:55:52 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/06 21:25:25 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strdup(const char *s)
{
	int	i;
	char	*ret;
	int	len;

	len = ft_strlen(s);
	ret =(char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return(0);
	i = 0;
	while(s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
