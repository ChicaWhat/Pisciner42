/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:19:06 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/25 12:00:38 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_cleanup(t_data *table, int error_code)
{
	if (error_code == 1 && table->mutex_dead)
		pthread_mutex_destroy(table->mutex_dead);
	if (error_code == 2 && table->mutex_dead)
	{
		pthread_mutex_destroy(table->mutex_dead);
		pthread_mutex_destroy(&table->print_mutex);
	}
	while (table->forks_inited >= 0)
	{
		pthread_mutex_destroy(&table->forks[table->forks_inited]);
		table->forks_inited--;
	}
	free(table->forks);
	free(table->mutex_dead);
	free(table->philos);
	free(table);
}

void	destroy_meal_mutex(t_data *table, int meals_inited)
{
	while (meals_inited >= 0)
	{
		pthread_mutex_destroy(&table->philos[meals_inited].meal_mutex);
		meals_inited--;
	}
}
