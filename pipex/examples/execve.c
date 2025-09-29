/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:50:33 by carmegon          #+#    #+#             */
/*   Updated: 2025/09/26 20:18:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int main(void)
{
	char *pathname;
	char *argv[] = {"ls", "-l", NULL};
	char *envp = NULL;
	pathname = "/usr/bin/ls";

	// Comprobamos que el ejecutable exista y va todo bien
	if (access(pathname, X_OK) == -1)
	{
		perror("Error: access");
		exit(1);
	}

	// Abrimos el archivo para redigirir stdout
	int fd;
	fd = open("salida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error: open salida.txt");
		exit(1);
	}

	// Guardar copia de stdout
	int copy_stdout;
	copy_stdout = dup(STDOUT_FILENO);
	if (copy_stdout == -1)
	{
		perror("Error: dup");
		close(fd);
		exit(1);
	}

	// Redirigir stdout al archivo
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Error: dup2");
		close(fd);
		close(copy_stdout);
	}
	// Ya no necesitamos el descriptor original
	close(fd);

	// Ejecutamos el comando
	execve(pathname, argv, &envp);

	// Si exceve falla, restauramos el stdout y mostramos error
	dup2(copy_stdout, STDOUT_FILENO);
	close(copy_stdout);
	perror("Error: execve");
	// La salida 127 no es aleatoria. El sistema lo interpreta como:
	// "El comando no se encontró o no se pudo ejecutar"
	exit(127);
}
