/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:11:24 by carmegon          #+#    #+#             */
/*   Updated: 2026/01/02 16:00:20 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Map a pixel value from one range to another (pixel coords to complex coords)
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

// Render the fractal pixel by pixel
void	render(t_fractal *f)
{
	int		x;
	int		y;
	double	c_real;
	double	c_imag;
	int		iteri;

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
			if (f->id == 0)
				iteri = mandelbrot(f, c_real, c_imag);
			else
				iteri = julia(f, c_real, c_imag);
			mlx_put_pixel(f->img, x, y, get_color(iteri, f->iterations));
			x++;
		}
		y++;
	}
}
