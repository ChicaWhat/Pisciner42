/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:27:45 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/20 16:28:10 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_gettimeofday(void)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + (tv.tv_usec / 1000));
}

long	ft_now(t_data *table)
{
	long	now;

	now = ft_gettimeofday() - table->start_time;
	return (now);
}

int	set_dead(t_philo *philo)
{
	long	now;

	pthread_mutex_lock(&philo->meal_mutex);
	now = ft_now(philo->table);
	if ((now - philo->last_meal_time) > philo->table->time_to_die)
	{
		pthread_mutex_lock(philo->table->mutex_dead);
		philo->table->dead_flag = 1;
		pthread_mutex_unlock(philo->table->mutex_dead);
		printf("Dead flag para el Philo [%d]: %d\n", philo->id, philo->table->dead_flag);
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}

void	smart_usleep(t_philo *philo, int time_to_wait)
{
	long	start;
	long	actual_time;

	start = ft_now(philo->table);
	actual_time = ft_now(philo->table);
	while ((actual_time - start) < time_to_wait)
	{
		actual_time = ft_now(philo->table);
		usleep(20);
	}
}
