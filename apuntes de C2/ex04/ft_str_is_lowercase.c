/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:18:31 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/12 13:01:02 by carmegon         ###   ########.fr       */
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

int	main()
{
	char res;
	res = ft_str_is_lowercase("ooo/&%$olaaaaa");
	res = res + '0';
	write(1, &res, 1);
	return(0);
}



