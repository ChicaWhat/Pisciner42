/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:31:25 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/12 14:09:53 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	res;
	i = 0;
	while(str[i] >= 'A' && str[i] <= 'Z')
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
	res = ft_str_is_uppercase("65434");
	res = res + '0';
	write(1, &res, 1);
	return (0);
}
