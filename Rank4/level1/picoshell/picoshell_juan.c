/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picoshell_juan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:55:52 by jbrosio           #+#    #+#             */
/*   Updated: 2026/06/17 17:49:33 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/* 
variable_global = errno;

if (picoshell(cmd))
{
	perror("picoshell :", variable_global);
}
variable_global = 155

picoshell : pipe fail
*/

int picoshell(char **cmds[])
{
	int i = 0; // iterador para los comandos
	int tmp_fd = 0; // fd temporal para utilizar en comandos anidados o no
	int	fd[2]; // files descriptors para usar o no pipe
	int pid; // variable que almacena el numero de procesos
	int pipe_exist = 0; // flag q determina el uso de pipe por comandos anidados

	// condicional para control de errores
	if (!cmds || !*cmds || !**cmds)
		return (0);
	while (cmds[i])
	{
		// inicializamos la flag a 0
		pipe_exist = 0;
		// En el caso de que haya mas de un comando se pone la flag a 1
		if (cmds[i + 1])
			pipe_exist = 1;
		// Si la flag esta levantada se hace un pipe (tuberia)
		if (pipe_exist)
			if (pipe(fd) < 0)
				return (1);
		// se hace fork para ejecutar el comando
		pid = fork();
		// si fork falla
		// v	v	 v
		if (pid < 0)
		{
			// se cierra el fd temporal en el caso 
			// de que se haya inicializado
			if (tmp_fd != 0)
				close(tmp_fd);
			// Si hubo pipe se cierran los fd
			if (pipe_exist)
			{
				close(fd[0]);
				close(fd[1]);
			}
			return (1);
		}
		// si es el hijo
		// v	v	 v
		else if (pid == 0)
		{
			// si el fd temporal tenia un fd 
			// de un pipe se duplica (fd[0])
			if (tmp_fd != 0)
			{
				dup2(tmp_fd, STDIN_FILENO);
				close(tmp_fd);
			}
			// si hubo pipe se duplica el fd[1]
			// si no se ejecuta simplemente el comando
			// ya que no es necesario crear un pipe
			if (pipe_exist)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
				close(fd[0]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		// si es el padre
		// v	v	 v
		else if (pid > 0)
		{
			// si el fd temporal contiene uno real se cierra
			if (tmp_fd != 0)
				close(tmp_fd);
			// si hubo pipe se guarda en fd temporal el fd[0]
			// se cierra el fd[1]
			if (pipe_exist)
			{
				tmp_fd = fd[0];
				close(fd[1]);
			}
			// si no hubo pipe se pone otra vez 0
			else
				tmp_fd = 0;
			// el padre espera al unico proceso
			wait(0);
		}
		i++;
	}
	if (tmp_fd != 0)
		close(tmp_fd);
	return (0);
}

// #include <unistd.h>
// #include <sys/wait.h>
// #include <stdlib.h>

// int picoshell(char **cmds[])
// {
// 	int i = 0, j;
// 	int tmp_fd = 0;
// 	int	fd[2];
// 	int pid;
// 	int pipe_exist = 0;
// 	char **cmd = (*cmds);

// 	if (!cmds || !*cmds || !**cmds)
// 		return (1);
// 	while (cmd[i])
// 	{
// 		j = 0;
// 		while (cmds[i + j] && cmds[i + j][0] != '|')
// 			j++;
// 		if (cmds[i + j] && cmds[i + j][0] == '|')
// 		{
// 			cmds[i + j] = NULL;
// 			pipe_exist = 1;
// 		}
// 		else
// 			pipe_exist = 0;
// 		if (pipe_exist)
// 			if (pipe(fd) < 0)
// 				return (1);
// 		pid = fork();
// 		if (pid < 0)
// 		{
// 			if (tmp_fd != 0)
// 				close (tmp_fd);
// 			if (pipe_exist)
// 			{
// 				close(fd[0]);
// 				close(fd[1]);
// 			}
// 			return (1);
// 		}
// 		else if (pid == 0)
// 		{
// 			if (tmp_fd != 0)
// 			{
// 				dup2(tmp_fd, STDIN_FILENO);
// 				close(tmp_fd);
// 			}
// 			if (pipe_exist)
// 			{
// 				dup2(fd[1], STDOUT_FILENO);
// 				close(fd[1]);
// 				close(fd[0]);
// 			}
// 			if (execvp(cmd[i], cmd + i) < 0)
// 				exit(1);
// 			exit(0);
// 		}
// 		else if (pid > 0)
// 		{
// 			if (tmp_fd != 0)
// 				close(tmp_fd);
// 			if (pipe_exist)
// 			{
// 				tmp_fd = fd[0];
// 				close(fd[1]);
// 			}
// 			else
// 				tmp_fd = 0;
// 			wait(0);
// 		}
// 		i = i + j;
// 		if (pipe_exist)
// 			i++;
// 	}
// 	if (tmp_fd != 0)
// 		close(tmp_fd);
// 	return (0);
// }

/*

Funciones permitidas: close, fork, wait, exit, execvp, dup2, pipe

FUNCION picoshell(cmds):

    VARIABLE tmp_fd = dup(STDIN_FILENO) (Inicializamos con una copia de la entrada estandar)
    VARIABLE i = 0

    MIENTRAS cmds[i] exista:
        
        1. BUSCAR FIN DEL COMANDO:
           Avanza un puntero auxiliar (ej: 'fin') desde cmds[i] 
           hasta encontrar "|" o NULL.
           Pon un NULL temporalmente donde está el "|" para que execvp sepa dónde parar.

        2. PREPARAR TUBERÍAS:
           Declarar fd[2].
           Si no es el último comando (encontramos un "|"):
               pipe(fd)

        3. FORK:
           Si fork() == 0 (HIJO):
               - Configurar Entrada:
                 dup2(tmp_fd, STDIN_FILENO)
                 close(tmp_fd)
               
               - Configurar Salida:
                 Si hay siguiente comando (hubo pipe):
                     dup2(fd[1], STDOUT_FILENO)
                     close(fd[0]) (Limpieza)
                     close(fd[1]) (Limpieza)
               
               - Ejecutar:
                 execvp(cmds[i], cmds + i) // cmds + i es el inicio del comando actual
                 Si falla, exit(1).
        
        4. LIMPIEZA DEL PADRE (¡CRUCIAL!):
           - dup2(fd[0], tmp_fd) -> Guardamos el lado de lectura para la siguiente vuelta.
                                    Al usar dup2, cerramos el tmp_fd viejo y ponemos el nuevo.
           - close(fd[0]) -> Ya lo duplicamos en tmp_fd, cerramos el original.
           - close(fd[1]) -> El padre no escribe.
           - wait() -> Esperamos al hijo actual.

        5. AVANZAR:
           i = posición del 'fin' + 1.

    Cerrar tmp_fd final.
    Retornar 0.
*/

int picoshell(char **cmds[])
{
	int	i = 0; // iterador de los comandos
	int	j; // iterador para buscar las "|"
	int pipe_exist; // flag de que hay una pipe en la linea de comando
	int	tmp_fd = 0; // duplicado de resguardo
	int fd[2]; // fd para crear la tuberia
	int pid; // pid del proceso fork
	char **com = (*cmds);

	// Si no existe la lista de comandos corta el programa
	if (!cmds || !cmds[0])
		return (1);
	while (com[i])
	{
		j = 0;
		pipe_exist = 0;
		// Bucle para buscar el "|"
		while (com[i + j] && com[i + j][0] != '|')
			j++;
		// Si hay un pipe se activa la flag y se intercambia por un NULL
		// El NULL se pone para poder "engañar" al execvp
		if (com[i + j] && com[i + j][0] == '|')
		{
			pipe_exist = 1;
			com[i + j] = NULL;
		}
		// Si existe el "|"
		// Se crea la tuberia
		if (pipe_exist)
			if (pipe(fd) < 0)
				return (1);
		// Se hace fork para poder manejar el comando
		pid = fork();
		// Si fork falla se cierran los fd y termina el programa 
		if (pid < 0)
		{
			if (tmp_fd != 0)
				close(tmp_fd);
			if (pipe_exist)
			{
				close(fd[0]);
				close(fd[1]);
			}
			return (1);
		}
		// Proceso hijo
		else if (pid == 0)
		{
			// Si tmp_fd tiene otro fd que no sea el de 0
			// Se duplica y se cierra
			if (tmp_fd != 0)
			{
				dup2(tmp_fd, STDIN_FILENO);
				close(tmp_fd);
			}
			// Si existe el pipe
			// Se duplica el fd de salida para pasarselo al siguiente
			if (pipe_exist)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
				close(fd[0]);
			}
			// Ejecucion del comando
			if (execvp(com[i], com+i) < 0)
				exit(1);
			exit(0);
		}
		// Proceso padre
		else if (pid > 0)
		{
			// Si tmp_fd no es 0
			// Se cierra
			if (tmp_fd != 0)
				close(tmp_fd);
			// Si existe el pipe
			// Se guarda el fd de entrada
			// Se cierra el de salida porque no se usa
			if (pipe_exist)
			{
				tmp_fd = fd[0];
				close(fd[1]);
			}
			// Si no existe se mantiene 0
			else
				tmp_fd = 0;
			// Esperamos a que termine el proceso hijo
			wait(0);
		}
		// El iterador toma el valor del fin del comando
		// Si existia un pipe se quedaria en NULL
		i = i + j;
		// En ese mismo caso de que el pipe exista
		// Se itera una vez mas para el siguiente comando
		if (pipe_exist)
			i++;
	}
	return (0);
}
