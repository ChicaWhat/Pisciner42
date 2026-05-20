/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:18:05 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/20 16:33:37 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* 
* COMENZAR CON EL ARREGLO DE LOS INIT_MUTEX Y COMPROBAR DATA RACE Y DEADLOCKS
? COMPROBAR LEAKS DE MEMORIA
! CREAR LA CONDICION DE QUE NO PASE DE 200 PHILOS
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