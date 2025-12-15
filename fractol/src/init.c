/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:32:26 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/15 22:28:23 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init(WIDTH, HEIGHT, fractal->fractal_name, 0);
	if (!fractal->mlx_connection)
		ft_error_mlx();
	printf("Qué guarda mlx_connection? %p\n", fractal->mlx_connection);
	mlx_loop(fractal->mlx_connection);
}
