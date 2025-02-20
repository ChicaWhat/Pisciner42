/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:02:46 by carmegon          #+#    #+#             */
/*   Updated: 2025/02/08 19:13:20 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_imput(char *str)
{
	int n;
	n = 0;
	while(str[n] != '\0')
	{
		write(1, str[n], 1);
		n++;
	}
}

int	main(int argc, char **argv)
{
	char str;
	ft_imput(str);
	write(1, &argc, 1);
	write(1, argv[1], 33);
	return (0);
}
