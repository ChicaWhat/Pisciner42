/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:59:39 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/30 23:37:37 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	stdlib -> malloc
	fcntl -> open
	string -> sterror
	unistd -> write, close
	stdio -> printf
	math -> para compilar con -lm
*/

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

/* Windows dimensions */
# define WIDTH 2560
# define HEIGHT 1600

typedef struct f
{
	//--- MLX ---//
	mlx_t		*mlx_connection;
	mlx_image_t	*img;
	//--- FRACTAL ---//
	char		*f_name;
	int			id;
	double		julia_real;
	double		julia_imag;
	//---RENDERING---//
	double		min_real;
	double		max_real;
	double		min_imag;
	double		max_imag;
	int			iterations;
	double		zoom;
}	t_fractal;

void	init_values(t_fractal *f);
int		ft_isspace(char c);
void	is_valid(char *str);
double	ft_double(char *str);
double	ft_atod(char *str);
void	parsing_av(int ac, char **av, t_fractal *f);
void	fractal_init(t_fractal *f);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	ft_close_hook(void *param);
void	ft_get_mouse(double xdelta, double ydelta, void *param);
double	map(double pixel, double min_map, double max_map, double total_pixels);
void	render(t_fractal *f);
int		julia(t_fractal *f, double z_re, double z_imag);
int		mandelbrot(t_fractal *f, double c_re, double c_imag);
void	ft_zoom(t_fractal *f);
int		get_color(int i, int max_iter);
void	ft_error_av(void);
void	ft_clean(t_fractal *f);
void	ft_error_mlx(void);

#endif