/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prueba.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:27:41 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/13 18:09:45 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int 	ant;

	i = 0;
	while (str[i] != '\0')
	{
		ant = i - 1;
		if (!(str[ant] >= '0' && str[ant] <= '9'))
		{
			if ((str[ant]>= 32 && str[ant] <=64) && (str[i] >= 'a' && str[i] <= 'z'))
                        	str[i] = str[i] - 32;
			else if (!(str[ant] > 32 && str[ant] <= 64) && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			else if (str[0] >= 'a' &&  str[0] <= 'z')
				str[i] = str[i] - 32;
		}
		i++;
	}

	return (str);
}

int	main()
{
	char cad[] = "salut, comment tu vAs ? 42MoTs quaPante-deux; cinquante+et+un";
	ft_strcapitalize(cad);
	write(1, &cad, 61);
	return (0);	
}
