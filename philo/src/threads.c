/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:18:17 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/20 16:20:08 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_philo_thread(t_philo *philo)
{
	int	i;

	if (philo->table->n_philos == 1)
	{
		pthread_create(&philo[0].thread, NULL, one_philo_routine, &philo[0]);
		pthread_join(philo[0].thread, NULL);
		return ;
	}
	if (pthread_create(&philo->table->monitor, NULL, routine_monitor, 
		philo->table) != 0)
		join_the_threads(philo->table, 0);
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
		printf("Unificando hilo [%d]\n", threads_init);
		threads_init--;
	}
	pthread_join(table->monitor, NULL);
}
