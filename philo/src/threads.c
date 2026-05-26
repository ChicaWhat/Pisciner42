/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:18:17 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/26 16:03:06 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	monitor_thread(t_data *table)
{
	if (pthread_create(&table->monitor, NULL, routine_monitor,
			table) == 0)
	{
		table->monitor_created = 1;
		return (0);
	}
	return (1);
}

void	ft_philo_thread(t_philo *philo)
{
	int	i;

	if (philo->table->n_philos == 1)
	{
		pthread_create(&philo[0].thread, NULL, one_philo_routine, &philo[0]);
		pthread_join(philo[0].thread, NULL);
		return ;
	}
	monitor_thread(philo->table);
	i = 0;
	while (i < philo->table->n_philos)
	{
		if (pthread_create(&philo[i].thread, NULL,
				routine, &philo[i]) != 0)
		{
			join_the_threads(philo->table, i);
			return ;
		}
		i++;
	}
}

void	join_the_threads(t_data *table, int threads_init)
{
	while (threads_init - 1 >= 0)
	{
		pthread_join(table->philos[threads_init - 1].thread, NULL);
		threads_init--;
	}
	if (table->monitor_created == 1)
		pthread_join(table->monitor, NULL);
}
