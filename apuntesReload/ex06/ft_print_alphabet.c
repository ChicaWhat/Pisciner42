/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:28:58 by carmegon          #+#    #+#             */
/*   Updated: 2025/04/07 19:11:11 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_print_alphabet(void)
{
	char alphabet;
	alphabet = 'a';

	while(alphabet <= 'z')
	{
		ft_putchar(alphabet);
		alphabet++;
	}
}

int	main()
{
	ft_print_alphabet();
	return (0);
}
