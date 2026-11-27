#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int	picoshell(char **cmds[])
{
	int		i;
	int		prev_fd;
	pid_t	pid;
	int		fd[2];
	
	if (!cmds || !*cmds)
		return (1);
	
	i = 0;
	prev_fd = -1;
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd) < 0)
		{
			if (prev_fd != -1)
				close (prev_fd);
			return (1);
		}
		pid = fork();
		if (pid < 0)
		{
			if (prev_fd != -1)
				close (prev_fd);
			if (cmds[i + 1])
			{
				close (fd[0]);
				close (fd[1]);
			}
			return (1);
		}
		if (pid == 0)
		{
			if (prev_fd != -1)
			{
				close (prev_fd);
				dup2 (prev_fd, STDIN_FILENO);
			}
			else if (cmds[i + 1])
			{
				close (fd[0]);
				dup2 (fd[1], STDOUT_FILENO);
				close (fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit (1);
		}
		else if (pid > 0)
		{
			if (prev_fd != -1)
			{
				close (prev_fd);
				prev_fd = -1;
			}
			else if (cmds[1 + i])
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
		;
	return (0);
	/*
	int		ret;
	int		status;
	pid_t	wpid;
	ret = 0;
	while ((wpid = wait(&status)) > 0)
	{
		if (status != 0)
			ret = 1;
	}
	return (ret);
	*/
}


/*
	TODO               Primera vuelta
	!PADRE  -----------------------------  HIJO
	*0 -> lectura STDIN                    0 -> lectura STDIN
	*1 -> escritura STDOUT  PIPE ------>   1 -> escritura STDOUT -> CERRAMOS ESTE CANAL
	*2 -> error                            2 -> error
	                                      *fd[0] -> LO CERRAMOS, PORQUE TIRA DEL STDIN DEL PADRE
										  *fd[1] -> Redireccionamos el STDOUT_FILENO aquí
	
	TODO                Segunda vuelta
	!PADRE -----------------------------------------------------------------  HIJO
	*0 -> lectura STDIN (redireccionamos)                                    0 -> STDIN (redireccionado)
	*1 -> escritura STDOUT                                                   1 -> STDOUT (redireccionado)
	*2 -> error                                                              2 -> error
	*fd[0] -> Asignamos el STDIN a la variable prev_fd (prev_fd = fd[0])    fd[0] -> cerramos el canal de lectura
	*fd[1] -> Se tiene que cerrar, porque el PADRE no lo usa                fd[1] -> redireccionamos el canal de escritura con dup2 (fd[1], STDOUT_FILENO)
*/