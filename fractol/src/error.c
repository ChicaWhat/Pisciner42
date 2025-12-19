/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:51:40 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/19 20:33:33 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_error_av(void)
{
	ft_putstr_fd("Invalid av:\n", 2);
	ft_putstr_fd("1. ./fractol mandelbrot\n", 2);
	ft_putstr_fd("2. ./fractol julia <real number> <imaginary number>\n", 2);
	exit(2);
}

void	ft_error_mlx(void)
{
	ft_putstr_fd("Error: MLX initialization failed\n", 2);
	exit(2);
}

void	ft_clean(t_fractal *f)
{
	mlx_terminate(f->mlx_connection);
}

//void mlx_delete_image(mlx_t* mlx, mlx_image_t* image);
