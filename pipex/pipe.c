/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:35:39 by carmegon          #+#    #+#             */
/*   Updated: 2025/08/14 14:15:22 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(void)
{
		int pipefd[2]; 
		// Array para el pipe [lectura=0 (stdout), escritura=1 (stdin)];
		// stdin(1) -> entrada estandar (teclado); stdout(0) -> salida estandar (pantalla);
		pid_t pid1;
		pid_t pid2;

		// Creo el pipe (comunicación entre procesos);
		if (pipe(pidefd) == -1)
		{
				perror("Error en el pipe");
				exit(EXIT_FAILURE);
		}

		// Primer fork() - Para el primer comando
		pid1 = fork();
		if (pid1 == -1)
		{
				perror("Error fork");
				exit(EXIT_FAILURE);
		}

		// Si todo sale bien, redirecciono la salida estandar (STDOUT) al pipe
		// Proceso 1
		if (pid1 == 0)
		{
				dup2(pipefd[1], STDOUT_FILENO);
		}

		// Cerramos descriptores no necesarios
		close(pipefd[0]); // No necesitamos leer
		close(pipefd[1]); // Ya redirigido con dup2

		// Ejecutar el primer comando (ls -l)
		char *cmd[1] = {"ls", "l", NULL};
		/*
			Array creado:          execve() lo interpreta como:
			+-----------+         +---------------------------+
			| cmd1[0] → "ls"      | argv[0] → "ls" (nombre)   |
			| cmd1[1] → "-l"      | argv[1] → "-l" (flag)     |
			| cmd1[2] → NULL      | argv[2] → NULL (fin)      |
			+-----------+         +---------------------------+
		*/
		if (access(cmd1[0], X_OK == 0))
		{
				execve[cmd[0], cmd1, NULL];
		}
}




