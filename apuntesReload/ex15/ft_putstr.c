/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:50:12 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/12 18:43:22 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char u)
{
	write(1, &u, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}

// En este caso, estoy creando una variable char que es un array, entonces a la hora de declararla 
// como paramentro en la funcion ft_putstr, no necesito usar un '&'.
// Solamente cuando la variable es de tipo NO puntero y la funcion SI espera un puntero se debe de
// emplear el '&'. O cuando se quiere pasar la direccion de memoria de una variable para modificarla.
int	main()
{
	char	str[] = "Hola";
	ft_putstr(str);
	return (0);
}
