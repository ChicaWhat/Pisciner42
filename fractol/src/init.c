/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:32:26 by carmegon          #+#    #+#             */
/*   Updated: 2026/01/02 16:12:16 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Initialize MLX, create window and image, register all callback hooks
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
	mlx_scroll_hook(f->mlx_connection, ft_get_mouse, f);
	mlx_loop(f->mlx_connection);
}

// Callback: Handle keyboard input (ESC key closes window)
void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(f->mlx_connection);
}

// Callback: Handle window close event (X button)
void	ft_close_hook(void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	mlx_close_window(f->mlx_connection);
}

// Callback: Handle mouse scroll for zoom
void	ft_get_mouse(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;

	(void)xdelta;
	f = (t_fractal *)param;
	f->zoom = 1.0;
	if (ydelta >= 1.0)
		f->zoom *= 0.95;
	else
		f->zoom /= 0.95;
	ft_zoom(f);
	render(f);
}

// Calculate new fractal after zoom
void	ft_zoom(t_fractal *f)
{
	double	new_radius_r;
	double	new_radius_i;
	double	real_center;
	double	imag_center;

	real_center = (f->max_real + f->min_real) / 2;
	imag_center = (f->max_imag + f->min_imag) / 2;
	new_radius_r = (f->max_real - f->min_real) / 2 * f->zoom;
	new_radius_i = (f->max_imag - f->min_imag) / 2 * f->zoom;
	f->max_real = real_center + new_radius_r;
	f->min_real = real_center - new_radius_r;
	f->max_imag = imag_center + new_radius_i;
	f->min_imag = imag_center - new_radius_i;
}
