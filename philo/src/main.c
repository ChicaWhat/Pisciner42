/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:18:05 by carmegon          #+#    #+#             */
/*   Updated: 2026/04/23 20:18:14 by carmegon         ###   ########.fr       */
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

void	smart_usleep(t_data *table, int time_to_wait)
{
	long	start;
	long	actual_time;

	start = ft_gettimeofday();
	actual_time = ft_gettimeofday();
	while ((actual_time - start) < time_to_wait)
	{
		actual_time = ft_gettimeofday();
		pthread_mutex_lock(table->mutex_dead);
		if (table->mutex_dead == 1)
		{
			pthread_mutex_unlock(table->mutex_dead);
			break ;
		}
		pthread_mutex_unlock(table->mutex_dead);
		usleep(500);
	}
}

void	*philo_routine(void *argv)
{
	t_philo	*philo;
	
	philo = (t_philo *)argv;
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("Soy Philo: [%d] y estoy vivo\n", philo->id);
	pthread_mutex_unlock(&philo->table->print_mutex);
	return (NULL);
}

void	join_the_threads(t_data *table, int threads_init)
{
	while (threads_init - 1 >= 0)
	{
		pthread_join(table->philos[threads_init - 1].thread, NULL);
		printf("Unificando hilo [%d]\n", threads_init);
		threads_init--;
	}
}

void	ft_philo_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->n_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, 
			philo_routine, &philo[i]) != 0)
		{
			join_the_threads(philo->table, i);
			return ;
		}
		i++;
	}
	join_the_threads(philo->table, i);
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
	ft_cleanup(table, 0, 0);
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