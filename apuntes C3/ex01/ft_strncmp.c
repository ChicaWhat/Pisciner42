/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:18:37 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/17 05:09:43 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
// Declaro una variable unsigned, porque en la función el parametro 'n' es unsigned tambien
	unsigned int	i;
// Creo un bucle que me recorra mis dos cadenas de caracteres siempre y cuando sean distintos al valor null '\0' y la variable i sea menor que n.
	i = 0;
	while ((s1[i] !='\0' && s2[i] != '\0') && i < n)
	{
// Entro al bucle si se cumplen dichas dichas condiciones y le digo, si las dos cadenas son diferentes entra en el condicional:
		if (s1[i] != s2[i])
// Si la s1 es menor que s2 me retornas un valor negativo
// Si s1 es mayor que s2 me retornas un numero positivo
			if (s1[i] < s2[i])
				return (-1);
			else
				return (1);
						
		i++;
// En caso de que las dos cadenas sean iguales me retornas 0
	}
	return (0);
}

int	main()
{
	char	*s1 = "ho";
	char	*s2 = "ho!arriVeeE&%";
	ft_strncmp(s1, s2, 5);
	return (0);
}

