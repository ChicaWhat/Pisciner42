/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:32:26 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/16 11:24:42 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	fractal_init(t_fractal *f)
{
	f->mlx_connection = mlx_init(WIDTH, HEIGHT, f->f_name, 0);
	if (!f->mlx_connection)
		ft_error_mlx();
	f->img = mlx_new_image(f->mlx_connection, WIDTH, HEIGHT);
	if (!f->img)
		ft_error_mlx();
	if (mlx_image_to_window(f->mlx_connection, f->img, 0, 0) == -1)
		ft_error_mlx();
	mlx_loop(f->mlx_connection);
}
