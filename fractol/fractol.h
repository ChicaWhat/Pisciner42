/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:59:39 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/15 22:20:38 by carmegon         ###   ########.fr       */
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
# define WIDTH 1920
# define HEIGHT 1080

typedef struct fractal
{
	//--- MLX ---//
	mlx_t		*mlx_connection;
	mlx_image_t	*img;
	//--- FRACTOL ---//
	char		*fractal_name;
	int			id;
	double		julia_real;
	double		julia_imaginary;
	//---RENDERIZADO---//
	double		escape_value;
	int			iterations;
	double		zoom;
}	t_fractal;

void	init_values(t_fractal *fractal);
int		ft_isspace(char c);
double	ft_double(char *str);
double	ft_atod(char *str);
void	parsing_av(int ac, char **av, t_fractal *fractal);
void	fractal_init(t_fractal *fractal);
void	ft_error_av(void);
void	clean_and_exit(t_fractal *fractal);
void	ft_error_mlx(void);

#endif