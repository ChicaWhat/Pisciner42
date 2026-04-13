/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:18:05 by carmegon          #+#    #+#             */
/*   Updated: 2026/04/13 20:08:07 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_data_struct(t_data *table, char **av)
{
	//t_philo	philo;

	table->n_philos = ft_atoi(av[0]);
	table->time_to_die = ft_atoi(av[1]);
	table->time_to_eat = ft_atoi(av[2]);
	table->time_to_sleep = ft_atoi(av[3]);
	//table->target_meals = ft_atoi(av[4]);
	table->start_time = 0;
	table->dead_flag = 0;
	//table->mutex_dead = 0;
	//table->forks = ft_atoi(av[1]);
	//table->philos = philo.table;
}

int main(int ac, char **av)
{
	t_data	table;
	check_av(ac, av);
	int i = 1;
	init_data_struct(&table, &av[i]);
	printf("%d\n", table.n_philos);
	printf("%d\n", table.time_to_die);
	printf("%d\n", table.time_to_eat);
	printf("%d\n", table.time_to_sleep);
/* 	while (av[i])
	{
		if (ft_atoi(av[i]) == -1)
		{
			printf("wrong number\n");
			return (0);
		}
		i++;
	} */
	return (0);
}