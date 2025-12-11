/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:01:51 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/10 17:56:55 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_daddy(char **av, char **envp, int *fd)
{
	pid_t	pid_first_child;
	pid_t	pid_second_child;

	pid_first_child = fork();
	if (pid_first_child < 0)
		pipex_error(1);
	else if (pid_first_child == 0)
		ft_first_child(av, envp, fd);
	else
	{
		close(fd[1]);
		pid_second_child = fork();
		if (pid_second_child < 0)
			pipex_error(1);
		else if (pid_second_child == 0)
			ft_second_child(av, envp, fd);
		else
		{
			close(fd[0]);
			waitpid(pid_first_child, NULL, 0);
			waitpid(pid_second_child, NULL, 0);
		}
	}
}

void	ft_first_child(char **av, char **envp, int *fd)
{
	char	**path;
	char	*command_path;
	char	**command_split;

	launch_first_child(av, fd);
	path = get_path(envp);
	if (!path)
		path_not_found(envp);
	command_split = check_commands(&av[2]);
	if (!command_split)
		ft_free_all(path, NULL, 127);
	command_path = get_command_path(path, command_split[0]);
	if (!command_path)
		ft_free_all(path, command_split, 127);
	if (execve(command_path, command_split, envp) == -1)
		ft_free_all(command_split, path, 127);
	exit(1);
}

void	ft_second_child(char **av, char **envp, int *fd)
{
	char	**path;
	char	*command_path;
	char	**command_split;

	launch_second_child(av, fd);
	path = get_path(envp);
	if (!path)
		path_not_found(envp);
	command_split = check_commands(&av[3]);
	if (!command_split)
		ft_free_all(path, NULL, 127);
	command_path = get_command_path(path, *command_split);
	if (!command_path)
		ft_free_all(command_split, path, 127);
	if (execve(command_path, command_split, envp) == -1)
		ft_free_all(command_split, path, 127);
	exit(1);
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];

	if (ac != 5)
	{
		write(2, "./pipex file1 comand1 comand2 file2\n", 36);
		return (1);
	}
	if (pipe(fd) == -1)
		pipex_error(24);
	ft_daddy(av, envp, fd);
	return (0);
}
