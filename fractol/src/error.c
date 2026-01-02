/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:51:40 by carmegon          #+#    #+#             */
/*   Updated: 2026/01/02 16:20:17 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_error_av(void)
{
	ft_putstr_fd("=== Invalid arguments ===\n\n", 2);
	ft_putstr_fd("Usage:\n", 2);
	ft_putstr_fd("  1. ./fractol mandelbrot\n\n", 2);
	ft_putstr_fd("  2. ./fractol julia <real> <imaginary>\n\n", 2);
	ft_putstr_fd("Julia examples:\n", 2);
	ft_putstr_fd("  ./fractol julia -0.8 0.156\n", 2);
	ft_putstr_fd("  ./fractol julia -0.704 0.296\n", 2);
	ft_putstr_fd("  ./fractol julia -0.704 0.265\n\n", 2);
	ft_putstr_fd("Controls:\n", 2);
	ft_putstr_fd("  - Mouse scroll: Zoom in/out\n", 2);
	ft_putstr_fd("  - ESC or X: Exit program\n\n", 2);
	exit(2);
}

void	ft_error_mlx(void)
{
	ft_putstr_fd("Error: MLX initialization failed\n", 2);
	exit(2);
}

void	ft_clean(t_fractal *f)
{
	mlx_delete_image(f->mlx_connection, f->img);
	mlx_terminate(f->mlx_connection);
}
