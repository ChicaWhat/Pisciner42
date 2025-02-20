/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:39:20 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/05 20:17:16 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;
	div = *a / *b;
	mod = *a % *b;
// Aquí estoy guardando el valor de la división en el puntero de a; mientras que en el puntero b se guarda
// el resultado del módulo de dicha división.
	*a = div;
	*b = mod;
}

int	main()
{
	int	a;
	int	b;
	int	c;
	a = 10;
	b = 5;
// Quiero comprobar que los resultados se están guardando en los punteros. Para ello, como el write no me devuelve
// numeros enteros, debo de sumar el caracter '0' + a porque, en este caso, estoy guardando el valor de la division
// en el puntera a.
	ft_ultimate_div_mod(&a, &b);
	c = '0' + a;
	write(1, &c, 1);
// Acá lo sumo con b, porque el modulo lo he guardado en dicho puntero.
	c = '0' + b;
	write(1, &c, 1);
	return (0);
}
