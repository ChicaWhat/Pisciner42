/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:59:20 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/11 13:16:39 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int ac, char **av)
{
	char	*error_msg = strerror(errno);

	(void)ac;
	(void)av;
	printf("Mensaje de error: %s\n", error_msg);
	return (0);
}
