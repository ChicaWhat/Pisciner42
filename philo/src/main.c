/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:18:05 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/13 18:17:38 by carmegon         ###   ########.fr       */
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

	pthread_mutex_lock(&philo->meal_mutex);
	now = ft_now(philo->table);
	if ((now - philo->last_meal_time) > philo->table->time_to_die)
	{
		pthread_mutex_lock(philo->table->mutex_dead);
		philo->table->dead_flag = 1;
		pthread_mutex_unlock(philo->table->mutex_dead);
		printf("Dead flag para el Philo [%d]: %d\n", philo->id, philo->table->dead_flag);
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
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
		usleep(20);
	}
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
	ft_putstr_fd(RED, 1);
	printf("%04ld Philo %d %s", ft_now(philo->table), philo->id, DIED);
	ft_putstr_fd(RST, 1);
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
	pthread_mutex_lock(philo->right_fork);
	smart_usleep(philo, 5);
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
/* 		if (set_dead(philo) == 1)
		{
			print_dead(philo);
			return (1);
		} */
	}
	else
	{
		ft_odd_philo(philo);
/* 		if (set_dead(philo) == 1)
		{
			print_dead(philo);
			return (1);
		} */
	}
	return (0);
}

int	philo_sleeping(t_philo *philo, int status)
{
	ft_print_mutex(philo, status);
	smart_usleep(philo, philo->table->time_to_sleep);
	pthread_mutex_lock(&philo->meal_mutex);
	if (philo->table->dead_flag == 1)
	{
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}

int	philo_thinking(t_philo *philo, int status)
{
	ft_print_mutex(philo, status);
	usleep(5);
	pthread_mutex_lock(&philo->meal_mutex);
	if (philo->table->dead_flag == 1)
	{
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
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
	pthread_join(table->monitor, NULL);
}
/* 
* COMENZAR CON EL ARREGLO DE LOS INIT_MUTEX Y COMPROBAR DATA RACE Y DEADLOCKS
? COMPROBAR LEAKS DE MEMORIA
! CREAR LA CONDICION DE QUE NO PASE DE 200 PHILOS
*/

void	*one_philo_routine(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	ft_print_mutex(philo, 1);
	smart_usleep(philo, philo->table->time_to_die);
	print_dead(philo);
	return (NULL);
}

void	*routine_with_av(void *argv)
{
	t_philo	*philo;
	//int		i;

	philo = (t_philo *)argv;
	//i = 0;
	while(1)
	{
		pthread_mutex_lock(&philo->meal_mutex);
		if (philo->meals_eaten == philo->table->target_meals)
		{
			pthread_mutex_unlock(&philo->meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->meal_mutex);
		if (philo_eating(philo) == 1)
			return (NULL) ;
		if (philo_sleeping(philo, 3) == 1)
			return (NULL) ;
		if (philo_thinking(philo, 4) == 1)
			return (NULL) ;
		usleep(5);
	}
	return (NULL);
}

void	*routine(void *argv)
{
	t_philo	*philo;
	
	philo = (t_philo *)argv;
	if (philo->table->target_meals != -1)
	{
		routine_with_av(philo);
		return (NULL);
	}
	while (1)
	{
		if (philo_eating(philo) == 1)
			break ;
		if (philo_sleeping(philo, 3) == 1)
			break ;
		if (philo_thinking(philo, 4) == 1)
			break ;
		usleep(5);
	}
	return (NULL);
}

int	all_philos_eaten(t_philo *philo)
{
	int	j;
	int all_done;

	j = 0;
	all_done = 1;
	while (j < philo->table->n_philos)
	{
		pthread_mutex_lock(&philo[j].meal_mutex);
		if (philo[j].meals_eaten < philo->table->target_meals)
			all_done = 0;
		pthread_mutex_unlock(&philo[j].meal_mutex);
		if (!all_done)
			break ;
		j++;
	}
	if (all_done)
		return (0);
	return (1);
}

void	*routine_monitor(void *argv)
{
	t_data	*table;
	int		i;

	table = (t_data *)argv;
	i = 0;
	while (1)
	{
		if (set_dead(&table->philos[i]) == 1)
		{
			print_dead(&table->philos[i]);
			break ;
		}
		if (all_philos_eaten(table->philos) == 0)
			break ;
		i = (i + 1) % table->n_philos;
		//usleep(5);
	}
	return (NULL);
}

void	ft_philo_thread(t_philo *philo)
{
	int	i;

	if (philo->table->n_philos == 1)
	{
		pthread_create(&philo[0].thread, NULL, one_philo_routine, &philo[0]);
		pthread_join(philo[0].thread, NULL);
		return ;
	}
	if (pthread_create(&philo->table->monitor, NULL, routine_monitor, 
		philo->table) != 0)
		join_the_threads(philo->table, 0);
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
	if (table->n_philos > 1)
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