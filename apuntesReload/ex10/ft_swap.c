/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:30:24 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/08 13:03:29 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	var;

	var = *a;
	*a = *b;
	*b = var;
}

int	main()
{
	int	a = 5;
	int	b = 3;

	// int	*c = &a;
	// int	*d = &b;

	printf("El valor de a es %d. El valor de b es %d\n", a, b);
	ft_swap(&a, &b);
	printf("El valor de a es %d. El valor de b es %d\n", a, b);
	return (0);
}


