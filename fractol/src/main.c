/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:59:20 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/30 20:10:27 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_values(t_fractal *f)
{
	f->mlx_connection = NULL;
	f->img = NULL;
	f->f_name = NULL;
	f->id = -1;
	f->julia_imag = 0.0;
	f->julia_real = 0.0;
	f->min_real = -2.0;
	f->max_real = +2.0;
	f->min_imag = -2.0;
	f->max_imag = +2.0;
	f->escape_value = 4.0; //? Buscar más adelante por qué inicializo a 4.0
	f->iterations = 42;
	f->zoom = 1.0;
}

void	parsing_av(int ac, char **av, t_fractal *f)
{
	if (ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 11)))
	{
		f->f_name = "mandelbrot";
		f->id = 0;
	}
	else if (ac == 4 && (!ft_strncmp(av[1], "julia", 6)))
	{
		f->f_name = "julia";
		f->id = 1;
		f->julia_real = ft_atod(av[2]);
		f->julia_imag = ft_atod(av[3]);
	}
	else
		ft_error_av();
}

int	main(int ac, char **av)
{
	t_fractal	f;

	init_values(&f);
	parsing_av(ac, av, &f);
	fractal_init(&f);
	ft_clean(&f);
	return (0);
}
