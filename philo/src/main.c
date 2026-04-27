/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:18:05 by carmegon          #+#    #+#             */
/*   Updated: 2026/04/27 18:53:56 by carmegon         ###   ########.fr       */
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
		if (table->dead_flag == 1)
		{
			pthread_mutex_unlock(table->mutex_dead);
			break ;
		}
		pthread_mutex_unlock(table->mutex_dead);
		usleep(500);
	}
}

void	ft_print_mutex(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	printf("%04ld Philo %d %s\n", ft_now(philo->table), philo->id, message);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	ft_odd_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	pthread_mutex_lock(philo->left_fork);
	ft_print_mutex(philo, "has taken the left fork");
	pthread_mutex_lock(philo->right_fork);
	ft_print_mutex(philo, "has taken the right fork");
	ft_print_mutex(philo, "is eating");
	philo->last_meal_time = ft_now(philo->table);
	smart_usleep(philo->table, philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_pair_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	pthread_mutex_lock(philo->right_fork);
	ft_print_mutex(philo, "has taken the right fork");
	pthread_mutex_lock(philo->left_fork);
	ft_print_mutex(philo, "has taken the left fork");
	ft_print_mutex(philo, "is eating");
	philo->last_meal_time = ft_now(philo->table);
	smart_usleep(philo->table, philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

/* 
* CAMBIAR NOMBRE DE LA FUNCION PHILO_ROUTINE Y PONERLE PHILO_EATING
! CREAR BUCLE INFINITO PARA LA RUTINA
? CREAR LA FUNCION PARA CAMBIAR LA FLAG DE DEAD_FLAG
*/
void	*philo_routine(void *argv)
{
	t_philo	*philo;
	
	philo = (t_philo *)argv;
	if (philo->id % 2 == 0)
	{
		smart_usleep(philo->table, philo->table->time_to_eat / 2);
		ft_pair_philo(philo);
		return (NULL);
	}
	ft_odd_philo(philo);
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