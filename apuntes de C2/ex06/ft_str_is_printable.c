/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:00:14 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/12 17:47:52 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int ft_str_is_printable(char *str)
{
	int	i;
	int	res;

	i = 0;
	while(str[i] >= 32 && str[i] <= 126)
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

int	main()
{
	int	result;
	result = ft_str_is_printable("è");
	result = result + '0';
	write(1, &result, 1);
	return (0);
}

