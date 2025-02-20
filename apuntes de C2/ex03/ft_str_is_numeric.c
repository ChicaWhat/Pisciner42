/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:07:48 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/11 21:33:42 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	res;
// Creamos un bucle practicamente igual que el anterior, cambiando solo los valores a digitos
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
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
	char	str;
	str = ft_str_is_numeric("! 45");
	str = str + '0';
	write (1, &str, 1);
	return (0);
}
