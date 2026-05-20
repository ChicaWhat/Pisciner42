/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:17:01 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/20 16:17:31 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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