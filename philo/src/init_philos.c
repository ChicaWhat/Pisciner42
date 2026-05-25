/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:22:27 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/25 12:37:17 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_one_philo(t_philo *philo, t_data *table, int i)
{
	philo->id = i + 1;
	philo->meals_eaten = 0;
	philo->last_meal_time = ft_now(table);
	philo->left_fork = &table->forks[i];
	philo->right_fork = &table->forks[(i + 1) % table->n_philos];
	philo->table = table;
}

void	init_philos(t_data *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		init_one_philo(&table->philos[i], table, i);
		i++;
	}
}
