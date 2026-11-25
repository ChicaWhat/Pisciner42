#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int		i;
	int		prev_fd;
	pid_t	pid;
	int		fd[2];

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
				close (fd[1]);
				close (fd[0]);
			}
			return (1);
		}
		if (pid == 0)
		{
			if (prev_fd != -1)
			{
				dup2 (prev_fd, STDIN_FILENO);
				close (prev_fd);
			}
			if (cmds[i + 1])
			{
				close (fd[0]);
				dup2 (fd[1], STDOUT_FILENO);
				close (fd[1]);
			}
			execvp (cmds[i][0], cmds[i]);
			exit (1);
		}
		else
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
		;
	/*
	! SI VEO QUE EN EL EXAMEN NO ME PASA EL PICOSHELL BIEN DEBO DE AÑADIR ESTAS LINEAS DE CODIGO
		*int		status;
		*int		ret;
		*pid_t	wpid;
		*while ((wpid = wait(&status)) > 0)
		*{
		*	if (status != 0)
		*		ret = 1;
		*}
		*return (ret);
	**/
	return (0);
}