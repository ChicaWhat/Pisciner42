/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:14:35 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/16 23:33:44 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;
	
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		i++;
	}
	if (s1[i] != s2[i])
		res = s1[i] - s2[i];
	else
		res = 0;
		
	return (res);
}

int	main()
{
	char	*s1 = "hola";
	char	*s2 = "ho";
	int	res;
	res = ft_strcmp(s1, s2) + '0';
	write(1, &res, 1);
	return (0);
}
