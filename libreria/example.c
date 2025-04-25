/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:01:12 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/25 15:16:55 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
// Aqui llamo a la biblioteca que estoy creando
#include "libft.h"

int	main(void)
{
	char t[] = "Menuda comida de cabeza";
	printf("%s\n", t);
	ft_bzero(t, 4);
	printf("%s\n", t);
	return (0);
}
