/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:30:07 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/09 13:46:50 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

#include <stdio.h>

int	main()
{
	int	a;
	int	b;
	int	div;
	int	mod;
	
	a = 10;
	b = 5;
	ft_div_mod(a, b, &div, &mod);
	printf("Resultado de la división: %d. Resultado del resto: %d\n", div, mod);
	return (0);
}
