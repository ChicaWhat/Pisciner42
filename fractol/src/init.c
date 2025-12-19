/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:32:26 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/19 20:51:26 by carmegon         ###   ########.fr       */
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
	{
		ft_clean(f);
		ft_error_mlx();
	}
	if (mlx_image_to_window(f->mlx_connection, f->img, 0, 0) == -1)
	{
		ft_clean(f);
		ft_error_mlx();
	}
	render(f);
	mlx_key_hook(f->mlx_connection, ft_key_hook, f);
	mlx_close_hook(f->mlx_connection, ft_close_hook, f);
	mlx_loop(f->mlx_connection);
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(f->mlx_connection);
}

void	ft_close_hook(void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	mlx_close_window(f->mlx_connection);
}
