/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:59:20 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/15 22:20:48 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_values(t_fractal *fractal)
{
	fractal->mlx_connection = NULL;
	fractal->img = NULL;
	fractal->fractal_name = NULL;
	fractal->id = -1;
	fractal->julia_imaginary = 0.0;
	fractal->julia_real = 0.0;
	fractal->escape_value = 4.0; //? Buscar más adelante por qué inicializo a 4.0
	fractal->iterations = 42; //? Por inicializarlo con algo
	fractal->zoom = 1.0; //? Zoom estandar
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


void	parsing_av(int ac, char **av, t_fractal *fractal)
{
	if (ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 11)))
	{
		fractal->fractal_name = "mandelbrot";
		fractal->id = 0;
		printf("El nombre de mi fractal: %s\n", fractal->fractal_name);
	}
	else if (ac == 4 && (!ft_strncmp(av[1], "julia", 6)))
	{
		fractal->fractal_name = "julia";
		fractal->id = 1;
		fractal->julia_real = ft_atod(av[2]);
		fractal->julia_imaginary = ft_atod(av[3]);
		printf("El nombre de mi fractal: %s\n", fractal->fractal_name);
		printf("Valor de julia imaginario: %f\n", fractal->julia_imaginary);
		printf("Valor de julia real: %f\n", fractal->julia_real);
	}
	else
		ft_error_av();
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	init_values(&fractal);
	parsing_av(ac, av, &fractal);
	fractal_init(&fractal);
	return (0);
}
