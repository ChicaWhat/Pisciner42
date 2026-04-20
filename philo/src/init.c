/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:19:44 by carmegon          #+#    #+#             */
/*   Updated: 2026/04/20 11:20:13 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_data2(t_data *table)
{
	int		forks_inited;
	int		dead_inited;

	forks_inited = 0;
	dead_inited = init_mutex(table, &forks_inited, &dead_inited, 0);
	table->start_time = 0;
	table->dead_flag = 0;
	if (dead_inited != 0)
	{
		ft_cleanup(table, forks_inited, dead_inited);
		return (1);
	}
	return (0);
}

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
	if (ac == 6)
		table->target_meals = ft_atoi(av[5]);
	else
		table->target_meals = -1;
	if (init_data2(table))
		return (NULL);
	return (table);
}

int	init_mutex(t_data *table, int *forks_inited, int *dead_inited, int i)
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
		*forks_inited = i;
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (2);
		i++;
	}
	table->philos = malloc(table->n_philos * sizeof(t_philo));
	if (!table->philos)
		return (2);
	return (0);
}

void	init_one_philo(t_philo *philo, t_data *table, int i)
{
	philo->id = i + 1;
	philo->meals_eaten = 0;
	philo->last_meal_time = table->start_time;
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
