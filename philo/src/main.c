/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:18:05 by carmegon          #+#    #+#             */
/*   Updated: 2026/05/25 11:20:42 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int ac, char **av)
{
	if (check_av(ac, av))
		return (1);
	else
		start_program(ac, av);
	return (0);
}

int	start_program(int ac, char **av)
{
	t_data	*table;
	int		meals_inited;

	table = init_data_struct(ac,av);
	if (!table)
		return (1);
	meals_inited = -1;
	if (init_mutex2(table, &meals_inited))
	{
		destroy_meal_mutex(table, meals_inited);
		ft_cleanup(table, 2);
		return (1);
	}
	init_philos(table);
	ft_philo_thread(table->philos);
	if (table->n_philos > 1)
		join_the_threads(table, table->n_philos);
	destroy_meal_mutex(table, meals_inited);
	ft_cleanup(table, 2);
	return (0);
}
