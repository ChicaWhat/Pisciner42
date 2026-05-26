/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:19:44 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/26 16:01:54 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_data	*init_data_struct(int ac, char **av)
{
	t_data	*table;

	table = malloc(sizeof(t_data));
	if (!table)
		return (NULL);
	table->forks = NULL;
	table->philos = NULL;
	table->mutex_dead = NULL;
	table->n_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->forks_inited = -1;
	table->monitor_created = 0;
	if (ac == 6)
		table->target_meals = ft_atoi(av[5]);
	else
		table->target_meals = -1;
	if (init_data2(table))
		return (NULL);
	return (table);
}

int	init_data2(t_data *table)
{
	int		dead_inited;

	dead_inited = init_mutex(table, &dead_inited, 0);
	table->start_time = ft_gettimeofday();
	table->dead_flag = 0;
	if (dead_inited != 0)
	{
		ft_cleanup(table, dead_inited);
		return (1);
	}
	return (0);
}

int	init_mutex(t_data *table, int *dead_inited, int i)
{
	table->mutex_dead = malloc(sizeof (pthread_mutex_t));
	if (!table->mutex_dead)
		return (1);
	*dead_inited = pthread_mutex_init(table->mutex_dead, NULL);
	if (*dead_inited != 0)
		return (1);
	*dead_inited = pthread_mutex_init(&table->print_mutex, NULL);
	if (*dead_inited != 0)
		return (2);
	table->forks = malloc(table->n_philos * sizeof(pthread_mutex_t));
	if (!table->forks)
		return (2);
	while (i < table->n_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (2);
		table->forks_inited = i;
		i++;
	}
	table->philos = malloc(table->n_philos * sizeof(t_philo));
	if (!table->philos)
		return (2);
	return (0);
}

int	init_mutex2(t_data *table, int *meals_inited)
{
	int	i;

	i = 0;
	*meals_inited = -1;
	while (i < table->n_philos)
	{
		if (pthread_mutex_init(&table->philos[i].meal_mutex, NULL) != 0)
			return (1);
		*meals_inited = i;
		i++;
	}
	return (0);
}
