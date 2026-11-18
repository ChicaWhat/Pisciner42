#include <unistd.h>
#include <sys/types.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	int		res;
	int		fd[2];
	pid_t	pid;

	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	if (pipe(fd) < 0)
		return (-1);
	res = -1;
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			close(fd[0]);
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
	else if (pid > 0)
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

