/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:58:25 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/22 19:42:15 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_color(int i, int max_iter)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	if (i == max_iter)
		return (0x000000FF);
	else
	{
		r = (i * 15) % 255;
		g = (i * 2) % 255;
		b = (i * 35) % 255;
	}
	return (((int)r << 24) | ((int)g << 16) | ((int)b << 8) | 0xFF);
}
