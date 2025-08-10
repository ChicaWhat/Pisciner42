/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:31:09 by carmegon          #+#    #+#             */
/*   Updated: 2025/08/10 16:36:38 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	access() function checks that the access or the command exists.
*/

#include "pipex.h"

int main(void)
{
		char *file = "prueba.txt";

		if (access(file, R_OK) == 0)
				printf("El archivo %s se puede leer\n", file);
		else
				perror("Error de acceso");
		return (0);
}
