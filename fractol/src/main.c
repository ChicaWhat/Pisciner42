/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:59:20 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/13 14:37:37 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_values(t_fractal *fractal)
{
	fractal->fractal_name = NULL;
	fractal->id = -1;
	fractal->julia_imaginary = 0.0;
	fractal->julia_real = 0.0;
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
	}
	else if (ac == 4 && (!ft_strncmp(av[1], "julia", 6)))
	{
		fractal->fractal_name = "julia";
		fractal->id = 1;
		fractal->julia_real = ft_atod(av[2]);
		fractal->julia_imaginary = ft_atod(av[3]);
	}
	else
		ft_error_av();
	//!Creo que aqui iria el init_values porque despues de comprobar que todo ha
	//!ido bien, debo de inicializarlo todo. Prefiero hacerlo aqui antes que en
	//!el main
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	parsing_av(ac, av, &fractal);
	//init_mlx();
	return (0);
}
