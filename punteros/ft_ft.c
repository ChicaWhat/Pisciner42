/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:19:55 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/03 14:11:58 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
	printf("La direccion de memoria de nbr es:%p \n", nbr);
	printf("El valor de nbr es: %d \n", *nbr);
	printf("Direccion: %p , Valor: %d \n", nbr, *nbr);
}

int	main(void)
{
	int	nbr;
	ft_ft(&nbr);
	return (0);
}
