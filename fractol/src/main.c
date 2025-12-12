/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:59:20 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/12 14:11:41 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_values(t_fractal *fractal)
{
	fractal->fractal_name = NULL;
	fractal->id = -1;
	fractal->julia_imaginary = 0.0;
	fractal->julia_real = 0.0;
}

void	parsing_av(int ac, char **av, t_fractal *fractal)
{
	if (ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 11)))
	{
		fractal->fractal_name = "mandelbrot";
		fractal->id = 0;
	}
	else if (ac == 4 && (!ft_strncmp(av[1], "julia", 6)))
	{
		fractal->fractal_name = "julia";
		fractal->id = 1;
		fractal->julia_real = ft_atod(av[2]);
		fractal->julia_imaginary = ft_atod(av[3]);
	}
	else
		ft_error_av();
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	parsing_av(ac, av, &fractal);
	init_mlx();
	return (0);
}
