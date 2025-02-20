/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:18:31 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/14 13:08:38 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	res;

	i = 0;
	while(str[i] >= 'a' && str[i] <= 'z')
	{
		i++;
	}

	if (str[i] == '\0')
	{
		res = 1;
	}
	else
	{
		res = 0;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	if(argc > 2)
	{
		write(1, "Solo dos argumentos", 20);
	}
	int	i;
	i = ft_str_is_lowercase(argv[i]);
	i = i + '0';
	write(1, &i, 1);
	return (0);
}



