/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:59:20 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/29 17:33:55 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_values(t_fractal *f)
{
	f->mlx_connection = NULL;
	f->img = NULL;
	f->f_name = NULL;
	f->id = -1;
	f->julia_imaginary = 0.0;
	f->julia_real = 0.0;
	f->min_real = -2.0;
	f->max_real = +2.0;
	f->min_imag = -2.0;
	f->max_imag = +2.0;
	f->escape_value = 4.0; //? Buscar más adelante por qué inicializo a 4.0
	f->iterations = 42;
	f->zoom = 1.0;
}

int	ft_isspace(char c)
{
	if (c < 33)
		return (1);
	return (0);
}

double	ft_double(char *str)
{
	double	div;
	int		i;
	double	num;
	double	digit;

	i = 0;
	num = 0.0;
	digit = 0;
	div = 1.0;
	while (ft_isdigit(str[i]))
	{
		div = div * 10;
		digit = str[i] - '0';
		num = num + (digit / div);
		i++;
	}
	return (num);
}

double	ft_atod(char *str)
{
	double	num;
	int		i;
	int		sign;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	num = 0.0;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	num += ft_double(&str[i]);
	return (num * sign);
}


void	parsing_av(int ac, char **av, t_fractal *f)
{
	if (ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 11)))
	{
		f->f_name = "mandelbrot";
		f->id = 0;
		printf("El nombre de mi f: %s\n", f->f_name);
	}
	else if (ac == 4 && (!ft_strncmp(av[1], "julia", 6)))
	{
		f->f_name = "julia";
		f->id = 1;
		f->julia_real = ft_atod(av[2]);
		f->julia_imaginary = ft_atod(av[3]);
		printf("El nombre de mi f: %s\n", f->f_name);
		printf("Valor de julia imaginario: %f\n", f->julia_imaginary);
		printf("Valor de julia real: %f\n", f->julia_real);
	}
	else
		ft_error_av();
}

int	main(int ac, char **av)
{
	t_fractal	f;

	init_values(&f);
	parsing_av(ac, av, &f);
	fractal_init(&f);
	ft_clean(&f);
	return (0);
}
