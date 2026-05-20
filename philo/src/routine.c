/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:21:48 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/20 16:49:55 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*one_philo_routine(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	ft_print_mutex(philo, 1);
	smart_usleep(philo, philo->table->time_to_die);
	print_dead(philo);
	return (NULL);
}

void	*routine_monitor(void *argv)
{
	t_data	*table;
	int		i;

	table = (t_data *)argv;
	i = 0;
	while (1)
	{
		if (set_dead(&table->philos[i]) == 1)
		{
			print_dead(&table->philos[i]);
			break ;
		}
		if (all_philos_eaten(table->philos) == 0)
			break ;
		i = (i + 1) % table->n_philos;
		usleep(500);
	}
	return (NULL);
}

void	*routine_with_av(void *argv)
{
	t_philo	*philo;
	//int		i;

	philo = (t_philo *)argv;
	//i = 0;
	while(1)
	{
		pthread_mutex_lock(&philo->meal_mutex);
		if (philo->meals_eaten == philo->table->target_meals)
		{
			pthread_mutex_unlock(&philo->meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->meal_mutex);
		if (philo_eating(philo) == 1)
			return (NULL) ;
		if (philo_sleeping(philo, 3) == 1)
			return (NULL) ;
		if (philo_thinking(philo, 4) == 1)
			return (NULL) ;
		usleep(5);
	}
	return (NULL);
}

void	*routine(void *argv)
{
	t_philo	*philo;
	
	philo = (t_philo *)argv;
	if (philo->table->target_meals != -1)
	{
		routine_with_av(philo);
		return (NULL);
	}
	while (1)
	{
		if (philo_eating(philo) == 1)
			break ;
		if (philo_sleeping(philo, 3) == 1)
			break ;
		if (philo_thinking(philo, 4) == 1)
			break ;
		usleep(5);
	}
	return (NULL);
}
