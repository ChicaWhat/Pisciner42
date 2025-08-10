/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:14:42 by carmegon          #+#    #+#             */
/*   Updated: 2025/08/10 16:30:30 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Si quiero que errno me devuelva algo diferente a "No such file or directory"
	debo de asignarle un valor nuevo. Ej:
	errno = EEXIST (el archivo ya existe);
*/

#include "pipex.h"

int main(void)
{
		int fd;
		fd = open("prueva.txt", O_RDONLY);
		//errno = EEXIST;

		if (fd == -1)
		{
				perror("Error con perror");
				printf("Error con strerror: %s\n", strerror(errno));
		}
		else
		{
				printf("Archivo arbierto correctamente (fd = %d)\n", fd);
				close(fd);
		}
		return (0);
}
