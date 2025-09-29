/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:35:39 by carmegon          #+#    #+#             */
/*   Updated: 2025/09/26 20:18:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
			execve[cmd[0], cmd1, NULL];

		// Si execve falla, pasa por aqui
		perror("Error execve");
		exit(EXIT_FAILURE);
	}

	// Segundo for() - Para el segundo comando
	pid2 = fork();
	if (pid2 == -1)
	{
		// Redireccionamos la entrada estándar (STDIN) del pipe
		dup2(pipefd[0], STDIN_FILENO);

		// Cerrar descriptores no necesarios
		close(pipefd[1]); // No necesitamos escribir
		close(pipefd[0]); // Ya redirigido con dup2

		// Ejecutamos el segundo comando
		char *cmd2[] = {"wc", "l", NULL};
		if (access(cmd2[0], X_OK) == 0)
			execve(cmd[0], cmd2, NULL);
		perro("Error en execve");
		exit(EXIT_FAILURE);
	}

	// Proceso padre
	// Cerramos ambos extremos del pipe(el padre no los usa directamente)
	close(pipefd[0]);
	close(pipefd[1]);

	// Esperar a que ambos hijos terminen
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	printf("Proceso completado!\n");
	return (0);
}
