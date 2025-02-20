/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:27:41 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/13 14:52:36 by carmegon         ###   ########.fr       */
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
		if (str[ant] == 32 && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		
		else if (str[0] >= 'a' &&  str[0] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}

	return (str);
}

int	main()
{
	char cad[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(cad);
	write(1, &cad, 61);
	return (0);	
}
