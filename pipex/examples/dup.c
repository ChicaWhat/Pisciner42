/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:08:33 by carmegon          #+#    #+#             */
/*   Updated: 2025/09/26 20:18:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- Con la funcion dup(fd) creo una copia del fd que apunta al mismo archivo que
	le paso por open() y el sistema me devuelve el menor numero libre disponible
	- Con dup2(old_fd, new_fd) new_fd apunta al mismo archivo que old_fd; si
	new_fd ya está abierto, lo cierra primero; yo elijo el numero exacto de new_fd
*/

#include "../pipex.h"

int main(void)
{
	int fd;
	int copy;

	fd = open("textoVacio.txt", O_WRONLY | O_CREAT, 0666);
	printf("%d\n", fd);
	copy = dup(STDOUT_FILENO); // STDOUT_FILENO (salida estándar, pantalla normalmente);
	dup2(fd, STDOUT_FILENO);   // Redirijo la salida stdout a mi archivo "textoVacio.txt";
	close(fd);				   // SIEMPRE se debe de cerrar el archivo;

	printf("Esto va a mi archivo vacio\n");
	dup2(copy, STDOUT_FILENO); // El stdout vuelve a apuntar a la pantalla;
	close(copy);

	printf("Esto va a la terminal\n");
}
