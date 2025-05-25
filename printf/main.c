/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:46:42 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/24 21:19:16 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	int	n = 869358;
	char	*ptr = "Hola buenos dias la re contra puta que me pario";
	unsigned int	num = 6554332;
	char	c = 65;
	char	d = '6';
	int	size;
	printf("Devolviendo un entero: %d\n", n);
	printf("Que dise mi ente %s\n", ptr);
	printf("Devolviendo un unsigned int: %u\n", num);
	printf("Jugando con hexad en minus: %x\ny en mayus: %X\n", n, n);
	size = printf("Esto me devuelve el valor de 65 en la tabla ascii: %c\n", c);
	printf("%d\n", size);
	printf("Esta es la variable de tipo char que me devuelve un entero: %d\nEsta es la varibale de tipo char que me devuelve el valor ascii del 6: %d", c, d);
	return (0);
}
