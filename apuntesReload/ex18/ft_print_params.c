/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:28:07 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/15 16:18:24 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

// Primera vez que creo un programa donde le paso argumentos al main
// Aqui tengo en cuenta argc (el numero de argumentos que va a tener mi programa) y **argv (el array de arrays para que me recorra cada argumento y me devuelva lo que yo le pida)
int	main(int argc, char *argv[])
{
	int	i;
	int	j;
// Creo un bucle para que me recorra el numero de argumentos que le voy a dar a mi programa. En el momento que el contador vaya a ser mayor que el numero de argumentos deja de entrar en el primer bucle.
// Es IMPORTANTISIMO tener en cuenta que la variable j DEBE de ir dentro del bucle, porque sino nunca me va a volver a 0 en cada argumento que me vaya a recorrer, sino que seguiria sumando y eso no lo queremos.
	i = 0;
	while (i < argc)
	{
		j = 0;
// Este segundo bucle me va a ir iterando mientras HAYA qué recorrer, cuando ya no tenga argumento que recorrer, sale y vuelve al primer bucle para ver si tenemos argumento o no que poder iterar.
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
// Aquí le pido un salto de linea
		ft_putchar('\n');
		i++;
	}
	return (0);
}
