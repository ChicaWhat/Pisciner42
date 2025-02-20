/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:04:48 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/11 19:11:31 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h> 

int	ft_str_is_alpha(char *str)
{
// Declaro dos variables: una para el bucle y otra para almacenar el resultado que quiero que me devuelva return
	int	i;
	int	res;
// Creo un bucle donde le pongo las condiciones que quiero que cumpla para que me recorra el array. 
// En caso de no cumplirlas, sale del bucle y entra en mis condicionales:
	i = 0;
	while ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
	{
		i++;
	}
// En caso de haber entrado en el bucle, significa que el final del array va a ser null (\0), entonces me retorna 1
// En caso de no cumplirse el bucle, viene a la primera condición y comprueba que el bucle esté vacio (tenga el caracter null). Entonces, me retornaria 1
	if (str[i] == '\0')
	{
		res = 1;
	}
// Si no se cumple nada de lo anterior significa que el array tiene otras caracteres como espacio, símbolos o algo que no es alfabetico y me retornaria 0.
	else
	{
		res = 0;
	}
	return (res);
}

int	main()
{
	char resultado;
	resultado = ft_str_is_alpha("amAAAAAAAlia");
	resultado = resultado + '0';
	write(1, &resultado, 1);
	return (0);
}
