/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_picoshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 15:39:41 by carmegon          #+#    #+#             */
/*   Updated: 2026/11/21 15:41:36 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int	ft_picoshell(char **cmds[])
{
	int		prev_fd; //Indica si hay un pipe anterior
	int		fd[2]; //Los fd que se usan
	int		pid; //Almacena el numero de procesos
	int		i; //Iterador 

	// Comprobamos que no nos pasen variables nulas
	if (!cmds || !*cmds || !**cmds)
		return (1);

	// Comenzamos el bucle para los comandos
	i = 0;
	prev_fd = 0;
	while (cmds[i])
	{
		if (prev_fd != 0) // Si no tenemos una pipe anterior
		{
			dup2(fd[1], STDOUT_FILENO);
			close (fd[1]);
		}
	}
}


