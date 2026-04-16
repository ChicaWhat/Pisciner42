/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 21:47:44 by carmegon          #+#    #+#             */
/*   Updated: 2026/04/16 16:56:31 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>

typedef struct s_philo t_philo;

typedef struct s_data
{
	int				n_philos; // av[1]
	int				time_to_die; // av[2]
	int				time_to_eat; // av[3]
	int				time_to_sleep; // av[4]
	int				target_meals; //! av[5] (opcional)
	long			start_time; // Hora a la que empieza todo
	int				dead_flag; // (0)->vivo (1)->muerto
	pthread_mutex_t	*mutex_dead; // candado que protege a dead_flag
	pthread_mutex_t	*forks; // tenedores en la mesa
	t_philo			*philos; // array que apunta a la struct de los philos
}	t_data;

typedef struct s_philo
{
	int				id; // identificador de cada philo
	int				meals_eaten; // contador de comidas realizadas para cuando tenga av[5]
	long			last_meal_time; // momento exacto en el que comienza la últitma comida
	pthread_mutex_t	*left_fork; // puntero al mutex del tenedor izquierda
	pthread_mutex_t	*right_fork; // puntero al mutex del tenedor derecho
	t_data			*table; // puntero a la struct t_data
}	t_philo;

int	is_digit(int c);
int	is_av_valid(char **av);
int	check_av(int ac, char **av);
int	ft_atoi(char *s);
int	main(int ac, char **av);

#endif