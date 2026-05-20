/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:33:23 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/20 16:33:41 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	all_philos_eaten(t_philo *philo)
{
	int	j;
	int all_done;

	j = 0;
	all_done = 1;
	while (j < philo->table->n_philos)
	{
		pthread_mutex_lock(&philo[j].meal_mutex);
		if (philo[j].meals_eaten < philo->table->target_meals)
			all_done = 0;
		pthread_mutex_unlock(&philo[j].meal_mutex);
		if (!all_done)
			break ;
		j++;
	}
	if (all_done)
		return (0);
	return (1);
}
