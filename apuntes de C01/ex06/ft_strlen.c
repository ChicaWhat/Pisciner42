/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:46:18 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/06 18:24:08 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
// Declaro una variable que me devuelva un numero entero
	int	i;
// Hago un bucle que vaya a recorrer  
	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main()
{
	char	*cad;
	int	j;

	cad = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un"; //61
	j = ft_strlen(cad);
	write(1, &j, 1);
	return (0);
}
// Esto me devuelve un '=' que corresponde al valor 61 en la tabla ascii, pero yo quiero que me devuelva el 64! Cómo coño lo haría??
