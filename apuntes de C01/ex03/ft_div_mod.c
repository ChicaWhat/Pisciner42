/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:50:54 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/05 19:09:09 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main()
{
// Aqui declaro 3 variables: div, mod y c, porque write no devuelve ningún numero entero, entonces voy a utilizar la variable c para que el ordenador me devuelva valores que estén relacionados con la tabla ascii
	int	div;
	int	mod;
	int 	c;
// Aqui llamo a la función de arriba y le paso 4 parametros: los valores de a y b, el amperstan de div y el amperstand de mod porque, en la función arriba se tratan de punteros. Entonces, quiero que me devuelva el valor que se va a guardar en los directorios del *div y del *mod.
	ft_div_mod(4, 2, &div, &mod);
// Acá creo el contenido de la variable c: sumo el caracter 0 al resultado que se va a guardar en la variable div. Esto lo hago porque write no me devuelve numeros enteros, entonces utilizo la suma de caracteres para que el ordenador me devuelva la posición del número que necesito 
	c = '0' + div;
	write(1, &c, 1);
	c = '0' + mod;
	write(1, &c, 1);
	return (0);	
}
