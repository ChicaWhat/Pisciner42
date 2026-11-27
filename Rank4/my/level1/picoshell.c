#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int	ft_picoshell(char **cmds[])
{
	int		i; // Iterador entre comandos
	pid_t	pid; // Guarda un numero válido creado durante el proceso fork(). (pid == 0 HIJO; pid < 0 PADRE)
	int		prev_fd; // Donde guardamos el fd (handle) de ESCRITURA en caso de haber una pipe anteriormente
	int		fd[2]; // Los fd que vamos a usar en el momento que creemos el pipe()

	//! COMPROBAMOS QUE NO NOS PASEN CMDS NULLOS
	if (!cmds || !*cmds)
		return (1);

	i = 0;
	prev_fd = -1;
	while (cmds[i])
	{
		//! Si existe un comando siguiente Y ADEMÁS tenemos un error a la hora de crear la pipe
		//! hay que comprobar que el prev_fd, es decir, el fd de LECTURA anterior exista.
		//! Si existe, lo tenemos que cerrar. Retornamos 1.
		if (cmds[i + 1] && pipe(fd) < 0)
		{
			if (prev_fd != -1)
				close(prev_fd);
			return (1);
		}
		//! Creamos el proceso HIJO y comprobamos que no haya un error en la creacion
		pid = fork();
		if (pid < 0)
		{
			//! SI LO HAY vemos si habia un pipe anterior abierto y lo cerramos 
			if (prev_fd != -1)
				close (prev_fd);
			//! Vemos también si existe un comando siguiente para cerrar los fd creados en el pipe(fd)
			if (cmds[i + 1])
			{
				close (fd[1]);
				close (fd[0]);
			}
			return (1);
		}
		//? DESPUÉS DE COMPROBAR QUE NO HAY ERRORES Y HEMOS CERRADO LOS FD PERTINENTES
		//? VAMOS CON EL PROCESO HIJO
		if (pid == 0)
		{
			if (prev_fd != -1)
			{
				dup2(prev_fd, STDIN_FILENO);
				close (prev_fd);
			}
			if (cmds[i + 1])
			{
				close (fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close (fd[1]);
			}
			//* UNA VEZ REDIRECCIONADAS LAS ENTRADAS Y SALIDAS CORRESPONDIENTES
			//* TENEMOS QUE ACTIVAR LOS COMANDOS
			execvp(cmds[i][0], cmds[i]);
			exit (1);
		}
		else //? ESTE ES EL PROCESO PADRE
		{
			if (prev_fd != -1)
			{
				close (prev_fd);
				prev_fd = -1;
			}
			if (cmds[i + 1])
			{
				close (fd[1]);
				prev_fd = fd[0];
			}
		}
		i++;
	}
	if (prev_fd != -1)
		close (prev_fd);
	while (wait(NULL) > 0)
	{
	}
	/*
	! SI VEO QUE EN EL EXAMEN NO ME PASA EL PICOSHELL BIEN DEBO DE AÑADIR ESTAS LINEAS DE CODIGO
	*int		status;
	*int		ret;
	*pid_t	wpid;
	*ret = 0;
	*while ((wpid = wait(&status)) > 0)
	*{
	*	if (status != 0)
	*		ret = 1;
	*}
	*return (ret);
	**/
	return (0);
}


