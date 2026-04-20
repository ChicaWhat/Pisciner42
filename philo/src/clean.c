/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:19:06 by carmegon          #+#    #+#             */
/*   Updated: 2026/04/20 11:19:35 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_cleanup(t_data *table, int forks_inited, int error_code)
{
	if (error_code == 1)
		pthread_mutex_destroy(table->mutex_dead);
	if (error_code == 2)
	{
		pthread_mutex_destroy(table->mutex_dead);
		pthread_mutex_destroy(&table->print_mutex);
	}
	while (forks_inited >= 0)
	{
		pthread_mutex_destroy(&table->forks[forks_inited]);
		forks_inited--;
	}
	free(table->forks);
	free(table->mutex_dead);
	free(table->philos);
	free(table);
}