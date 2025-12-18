/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:32:24 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/18 17:50:04 by carmegon         ###   ########.fr       */
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

void	render(t_fractal *f)
{
	int		x;
	int		y;
	double	point_real;
	double	point_imag;

	y = 0;
	if (!f || !f->mlx_connection)
		ft_clean(f);
	while (y < HEIGHT)
	{
		x = 0;
		point_imag = map(y, f->min_imag, f->max_imag, HEIGHT);
		while (x < WIDTH)
		{
			point_real = map(x, f->min_real, f->max_real, WIDTH);
			x++;
		}
		y++;
	}
}
