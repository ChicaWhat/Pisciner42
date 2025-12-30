/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:32:24 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/30 20:12:20 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_fractal *f, double c_re, double c_imag)
{
	double	z_re;
	double	z_imag;
	int		i;
	double	aux;

	z_re = 0.0;
	z_imag = 0.0;
	i = 0;
	while (((z_re * z_re) + (z_imag * z_imag) <= 4.0) && i < f->iterations)
	{
		aux = z_re;
		z_re = ((z_re * z_re) - (z_imag * z_imag)) + c_re;
		z_imag = 2 * (aux * z_imag) + c_imag;
		i++;
	}
	return (i);
}



