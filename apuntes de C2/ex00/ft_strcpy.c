/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:12:15 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/11 10:07:51 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
// Creo un bucle para recorrer el array donde tengo una cadena de caracteres
	i = 0;
	while (src[i] != '\0')
	{
// Le doy al array vacio el valor del array donde habia info
		dest[i] = src[i];
		//write(1, &dest[i], 1);
		i++;
	}
// Aquí le digo al nuevo array que tome el valor de null antes del return para que llegue a su fin
	dest[i] = '\0';
	return (dest);
}

int	main()
{
// Creo dos arrays, uno con valor y otro vacío
	char	*var;
	char	varfinal[3];
	var = "hola";
// Aquí llamo a la funcion de arriba y coloco los arrays donde corresponden
	ft_strcpy(varfinal, var);
	write(1, varfinal, 3);
	return (0);
}
