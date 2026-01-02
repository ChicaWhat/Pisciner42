/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:01:52 by carmegon          #+#    #+#             */
/*   Updated: 2026/01/02 16:02:26 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Calculate Julia set: z = z² + c, where c is constant and z varies per pixel
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
	-0.8 0.156;
	-0.123 0.745;
	0.285 0.01;
	-0.704 0.296;
	-0.704 0.265;
	-0.763 0.092;
*/