/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:09:49 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/12 19:59:24 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char	*ft_strupcase(char *str)
{
	int	i;
	//char	p;
	//p = str[i];
// Creo un bucle que entre cuando el array no sea nulo.
	i = 0;
	while(str[i] != '\0')
	{
// Hago un condicional que me diga, si la posición del array se encuentra entre las minúsculas,
// me las vuelves mayúsculas restandole 32.
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;		
		}
		i++;
	}
	return (str);	
}

int	main()
{
	char	res[] = "hhoo(l)&$&%$··a";
	ft_strupcase(res);
	write(1, &res, 20);
	return (0);
}
