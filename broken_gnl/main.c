/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:25:41 by carmegon          #+#    #+#             */
/*   Updated: 2026/01/18 22:25:41 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n-- > 0)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}

int main(void)
{
    char *s1 = "Hola como estas";
    char s2[10];
    size_t n = 4;
    printf("%s\n", (char *)ft_memcpy(s2, s1, n));
    return (0);
}
