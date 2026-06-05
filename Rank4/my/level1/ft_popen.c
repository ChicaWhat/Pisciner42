#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	int		res;
	int		fd[2];
	pid_t	pid;

	//! Comprobar que los punteros contienen info y la variable type sea distinta
	//! a 'r' o 'w'
	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	//! Creamos el pipe ANTES de hacer fork(), porque si llamamos antes a fork()
	//! se crearan procesos de Padre e Hijo sin estar conectados entre si
	if (pipe(fd) < 0)
		return (-1);
	//* Le damos valores a la variable res y creamos el proceso Hijo
	res = -1;
	pid = fork();
	//* Si hay algún problema, cerramos los fd creados y retornamos -1
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	else if (pid == 0) //? PROCESO HIJO
	{
		if (type == 'r')
		{
			close(fd[0]);
			//* dup2(oldfd, newfd);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
		}
		else if (type == 'w')
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
		}
		if (execvp(file, argv) < 0)
			exit (1);
		exit (0);
	}
	else if (pid > 0) //? PROCESO PADRE
	{
		if (type == 'r')
		{
			close(fd[1]);
			res = fd[0];
		}
		else if (type == 'w')
		{
			close(fd[0]);
			res = fd[1];
		}
	}
	return (res);
}
