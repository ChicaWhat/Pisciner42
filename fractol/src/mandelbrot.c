/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:32:24 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/19 21:30:55 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(double pixel, double min_map, double max_map, double total_pixels)
{
	double	range;
	double	percent_pixel;
	double	result;

	range = max_map - min_map;
	percent_pixel = (pixel / total_pixels);
	result = (percent_pixel * range) + min_map;
	return (result);
}

int	mandelbrot(t_fractal *f, double c_re, double c_imag)
{
	double	z_re;
	double	z_imag;
	int		i;

	z_re = 0.0;
	z_imag = 0.0;
	i = 0;
	while ((z_re < 4 && z_imag < 4) && i <= f->iterations)
	{
		z_re = (z_re * z_re) + c_re;
		z_imag = (z_imag * z_imag) + c_imag;
		i++;
	}
	return (i);
}

void	render(t_fractal *f)
{
	int		x;
	int		y;
	double	c_real;
	double	c_imag;

	y = 0;
	if (!f || !f->mlx_connection)
		ft_clean(f);
	while (y < HEIGHT)
	{
		x = 0;
		c_imag = map(y, f->min_imag, f->max_imag, HEIGHT);
		while (x < WIDTH)
		{
			c_real = map(x, f->min_real, f->max_real, WIDTH);
			mlx_put_pixel(f->img, x, y, 0xFF0000FF);
			x++;
		}
		y++;
	}
}

//void mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color);
