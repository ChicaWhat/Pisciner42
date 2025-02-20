/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:15:08 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/11 12:28:20 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
// Creamos dos bucles. Uno para comprobar que, cuando el array no llega a null y la i es menor que n, me va a imprimir n caracteres del array principal
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		write(1, &dest[i], 1);
		i++;
	}
// El segundo bucle da por hecho que el array segundo va a ser mayor que el array primero y me va a reñenar los huecos restantes de '-'
	while (i <= n)
	{
		dest[i] = '-';
		write(1, &dest[i], 1);
		i++;
	}
	return (dest);
}

int	main()
{
// Aquí compruebo que mi función sirve ^^
	char *var;
	char varfinal[27];
	var = "Hola, mundo, la puta madre";
	ft_strncpy(varfinal, var, 40);
	return (0);
}
