/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:18:05 by carmegon          #+#    #+#             */
/*   Updated: 2026/04/13 14:38:57 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


int main(int ac, char **av)
{
	check_av(ac, av);
	int i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) == -1)
		{
			printf("wrong number\n");
			return (0);
		}
		i++;
	}
	return (0);
}