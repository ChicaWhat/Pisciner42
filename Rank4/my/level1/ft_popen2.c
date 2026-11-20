#include <unistd.h>
#include <sys/types.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	//! Creo las variables que necesito
	int		res;
	int		fd[2];
	pid_t	pid;

	//! Compruebo que me vayan a pasar los parametros con info
	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	
	//! Tengo que crear el pipe primero, antes de crear al HIJO y comprobar que no haya ningun error
	if (pipe(fd) < 0)
		return (-1);

	//! Hago un fork() para crear al proceso HIJO
	res = -1;
	pid = fork();

	//! En caso de que haya un error al haber creado al proceso HIJO, se deben de cerrar los 2 fd creados anteriormente
	if (pid < 0)
	{
		close (fd[1]);
		close (fd[0]);
		return (-1);
	}

	//! Ahora si puedo crear las condiciones para el proceso HIJO
	else if (pid == 0) //? PROCESO HIJO
	{
		if (type == 'r') //* EL HIJO VA A ESCRIBIR, EL PADRE LEERÁ
		{
			close (fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close (fd[1]);
		}
		else if (type == 'w') //* EL HIJO VA A LEER, EL PADRE ESCRIBIRÁ
		{
			close (fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close (fd[0]);
		}
		if (execvp(file, argv) < 0) //* SE EJECUTA EL PROCESO HIJO
			exit (1);
		exit (0);
	}
	else if (pid > 0) //? PROCESO PADRE
	{
		if (type == 'r')
		{
			close (fd[1]);
			res = fd[0];
		}
		else if (type == 'w')
		{
			close (fd[0]);
			res = fd[1];
		}
	}
	return (res);
}
