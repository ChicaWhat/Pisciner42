/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:18:05 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/11 20:57:23 by carmegon         ###   ########.fr       */
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

int	set_dead(t_philo *philo)
{
	long	now;

	now = ft_now(philo->table);
	//pthread_mutex_lock(&philo->meal_mutex);
	if ((now - philo->last_meal_time) > philo->table->time_to_die)
	{
		pthread_mutex_lock(philo->table->mutex_dead);
		philo->table->dead_flag = 1;
		pthread_mutex_unlock(philo->table->mutex_dead);
		printf("Dead flag para el Philo [%d]: %d\n", philo->id, philo->table->dead_flag);
		//pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	//pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}

void	smart_usleep(t_philo *philo, int time_to_wait)
{
	long	start;
	long	actual_time;

	start = ft_now(philo->table);
	actual_time = ft_now(philo->table);
	while ((actual_time - start) < time_to_wait)
	{
		actual_time = ft_now(philo->table);
		//pthread_mutex_lock(table->mutex_dead);
		if (set_dead(philo) == 1)
		{
			print_dead(philo);
			//pthread_mutex_unlock(table->mutex_dead);
			break ;
		}
		//pthread_mutex_unlock(table->mutex_dead);
		usleep(500);
	}
	//! Añadido esta comprobacion. No se si esta bien o no
/* 	pthread_mutex_lock(table->mutex_dead);
	if (set_dead(table->philos) == 1)
		print_dead(table->philos);
	pthread_mutex_unlock(table->mutex_dead); */
}

void	ft_print_mutex(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	if (status == 1)
	{
		ft_putstr_fd(CYAN, 1);
		printf("%04ld Philo %d %s", ft_now(philo->table), philo->id, TAKENFRK);
	}
	else if (status == 2)
	{
		ft_putstr_fd(GREEN, 1);
		printf("%04ld Philo %d %s", ft_now(philo->table), philo->id, EATING);
	}
	else if (status == 3)
	{
		ft_putstr_fd(PURPLE, 1);
		printf("%04ld Philo %d %s", ft_now(philo->table), philo->id, SLEEPING);
	}
	else if (status == 4)
	{
		ft_putstr_fd(BLUE, 1);
		printf("%04ld Philo %d %s", ft_now(philo->table), philo->id, THINKING);
	}
	ft_putstr_fd(RST, 1);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	print_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	ft_putstr_fd(RED, 2);
	printf("%04ld Philo %d %s", ft_now(philo->table), philo->id, DIED);
	ft_putstr_fd(RST, 2);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	ft_odd_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	ft_print_mutex(philo, 1);
	ft_print_mutex(philo, 2);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = ft_now(philo->table);
	smart_usleep(philo, philo->table->time_to_eat);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_pair_philo(t_philo *philo)
{
	//pthread_mutex_lock(&philo->meal_mutex);
	//smart_usleep(philo->table, philo->table->time_to_eat / 2);
	pthread_mutex_lock(philo->right_fork);
	smart_usleep(philo, philo->table->time_to_eat / 2);
	pthread_mutex_lock(philo->left_fork);
	ft_print_mutex(philo, 1);
	ft_print_mutex(philo, 2);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = ft_now(philo->table);
	smart_usleep(philo, philo->table->time_to_eat);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	philo_eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		ft_pair_philo(philo);
		if (set_dead(philo) == 1)
		{
			print_dead(philo);
			return (1);
		}
	}
	else
	{
		ft_odd_philo(philo);
		if (set_dead(philo) == 1)
		{
			print_dead(philo);
			return (1);
		}
	}
	return (0);
}

int	philo_sleeping(t_philo *philo, int status)
{
	ft_print_mutex(philo, status);
	smart_usleep(philo, philo->table->time_to_sleep);
	if (philo->table->dead_flag == 1)
		return (1);
	return (0);
}

int	philo_thinking(t_philo *philo, int status)
{
	ft_print_mutex(philo, status);
	smart_usleep(philo, philo->table->time_to_die);
	if (philo->table->dead_flag == 1)
		return (1);
	return (0);
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

void	*routine(void *argv)
{
	t_philo	*philo;
	
	philo = (t_philo *)argv;
	while (1)
	{
		if (philo_eating(philo) == 1)
			break ;
		if (philo_sleeping(philo, 3) == 1)
			break ;
		if (philo_thinking(philo, 4) == 1)
			break ;
	}
	return (NULL);
}

void	ft_philo_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->n_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, 
			routine, &philo[i]) != 0)
		{
			join_the_threads(philo->table, i);
			return ;
		}
		i++;
	}
}

/* int	two_options(t_data *table)
{
	if (table->target_meals == -1)
		infinite_loop(table);
	else
		loop_with_end(table);
	return (0);
} */

/* int	loop_with_end(t_data *table)
{
	ft_philo_thread(table->philos);
	while (table->philos->meals_eaten <= table->target_meals)
	{
		ft_philo_thread(table->philos);
	}
	return (0);
} */

/* void	infinite_loop(t_data *table)
{
	while (1)
	{
		ft_philo_thread(table->philos);
		if (table->dead_flag == 1)
			break ;
	}
} */

/* 
* Crear el hilo del monitor y que comience a comprobar si mueren o no
? Comenzar a ver los data race y deadlocks
*/

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
	join_the_threads(table, table->n_philos);
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