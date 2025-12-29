/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:01:52 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/29 22:09:59 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	julia(t_fractal *f, double z_re, double z_imag)
{
	double	c_real;
	double	c_imag;
	int		i;
	double	aux;

	c_real = f->julia_real;
	c_imag = f->julia_imag;
	i = 0;
	while (((z_re * z_re) + (z_imag * z_imag) <= 4.0) && i < f->iterations)
	{
		aux = z_re;
		z_re = ((z_re * z_re) - (z_imag * z_imag)) + c_real;
		z_imag = 2 * (aux * z_imag) + c_imag;
		i++;
	}
	return (i);
}

// --- Values to julia_real and julia_imag --- //
/* 
	av2 = -0.8;
	av3 = 0.156;

	av2 = -0.123;
	av3 = 0.745;

	av2 = 0.285;
	av3 = 0.01
*/