/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:31:46 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/26 18:09:52 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_odd_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	ft_print_mutex(philo, 1);
	ft_print_mutex(philo, 1);
	ft_print_mutex(philo, 2);
	smart_usleep(philo, philo->table->time_to_eat);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = ft_now(philo->table);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_pair_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	ft_print_mutex(philo, 1);
	ft_print_mutex(philo, 1);
	ft_print_mutex(philo, 2);
	smart_usleep(philo, philo->table->time_to_eat);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = ft_now(philo->table);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	philo_eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_pair_philo(philo);
	else
		ft_odd_philo(philo);
	return (0);
}

int	philo_sleeping(t_philo *philo, int status)
{
	pthread_mutex_lock(philo->table->mutex_dead);
	if (philo->table->dead_flag == 1)
	{
		pthread_mutex_unlock(philo->table->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(philo->table->mutex_dead);
	ft_print_mutex(philo, status);
	smart_usleep(philo, philo->table->time_to_sleep);
	return (0);
}

int	philo_thinking(t_philo *philo, int status)
{
	pthread_mutex_lock(philo->table->mutex_dead);
	if (philo->table->dead_flag == 1)
	{
		pthread_mutex_unlock(philo->table->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(philo->table->mutex_dead);
	ft_print_mutex(philo, status);
	return (0);
}
