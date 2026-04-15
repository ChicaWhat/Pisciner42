/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:18:05 by carmegon          #+#    #+#             */
/*   Updated: 2026/04/15 22:43:15 by carmegon         ###   ########.fr       */
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
	table->n_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->target_meals = ft_atoi(av[5]);
	else
		table->target_meals = -1;
	table->start_time = 0;
	table->dead_flag = 0;
	if (init_mutex(table))
	{
		free(table);
		return (NULL);
	}
	return (table);
}

int	init_mutex(t_data *table)
{
	int	i;
	
	i = 0;
	if (pthread_mutex_init(&table->mutex_dead, NULL) != 0)
		return (1);
	table->forks = malloc(table->n_philos * sizeof(pthread_mutex_t));
	if (!table->forks)
		return (1);
	while (i < table->n_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	table->philos = malloc(table->n_philos * sizeof(t_philo));
	if (!table->philos)
		return (1);
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

int main(int ac, char **av)
{
	t_data	*table;
	if (check_av(ac, av))
		return (1);
	table = init_data_struct(ac,av);
	if (!table)
		return (1);
	printf("%d\n", table->n_philos);
	printf("%d\n", table->time_to_die);
	printf("%d\n", table->time_to_eat);
	printf("%d\n", table->time_to_sleep);
/* 	while (av[i])
	{
		if (ft_atoi(av[i]) == -1)
		{
			printf("wrong number\n");
			return (0);
		}
		i++;
	} */
	return (0);
}