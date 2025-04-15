/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:01:50 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/15 10:40:39 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && res == 0)
	{
		if (s1[i] != s2[i])
			res = s1[i] - s2[i];
		i++;
	}
	return (res);
}
