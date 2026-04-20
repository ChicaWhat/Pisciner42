/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:18:05 by carmegon          #+#    #+#             */
/*   Updated: 2026/04/20 18:43:13 by carmegon         ###   ########.fr       */
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

void	*philo_routine(void *argv)
{
	t_philo	*philo;
	int		i;
	
	philo = (t_philo *)argv;
	i = 0;
	while (i < philo->table->n_philos)
	{
		printf("%d\n", philo->table->n_philos);
		printf("Soy Philo: [%d] y estoy vivo\n", philo[i].id);
		i++;
	}
	return (NULL);
}

void	ft_philo_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->n_philos)
	{
		pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]);
		i++;
	}
	//! Aqui me falta el pthread_join
}

/* long	ft_last_meal(t_data *table)
{
	long	time_without_eat;
	time_without_eat = ft_now(table) - table->philos->last_meal_time;
	return (time_without_eat);
}

void	assign_last_meal(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->table->n_philos)
	{
		philos[i].last_meal_time = ft_last_meal(philos->table);
		if (philos[i].last_meal_time >= philos->table->time_to_die)
		{
			printf("Estoy muerto\n");
		}
		i++;
	}
} */

int main(int ac, char **av)
{
	t_data	*table;
	if (check_av(ac, av))
		return (1);
	table = init_data_struct(ac,av);
	if (!table)
		return (1);
	init_philos(table);
	ft_philo_thread(table->philos);
	//printf_each_philo(table);
	free(table);
	return (0);
}

void	printf_each_philo(t_data *table)
{
	int i = 0;
	while (i < table->n_philos)
	{
		printf("-----------------------------------\n");
		printf("N de philo: %d\n", i);
		printf("id: %d\n", table->philos[i].id);
		printf("meals_eaten: %d\n", table->philos[i].meals_eaten);
		printf("last_meal_time: %ld\n", table->philos[i].last_meal_time);
		i++;
	}
}