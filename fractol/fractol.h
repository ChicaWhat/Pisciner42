/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:59:39 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/12 13:13:59 by carmegon         ###   ########.fr       */
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

typedef struct fractal
{
	char	*fractal_name;
	int		id;
	double	julia_real;
	double	julia_imaginary;
}	t_fractal;

void	ft_error_av(void);

#endif