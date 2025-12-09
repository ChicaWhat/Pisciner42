/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:01:59 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/09 18:19:26 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	launch_first_child(char **av, int *fd)
{
	int	input_fd;

	close(fd[0]);
	input_fd = open(av[1], O_RDONLY);
	if (input_fd == -1)
		pipex_error(2);
	if (dup2(input_fd, STDIN_FILENO) == -1)
		pipex_error(9);
	close(input_fd);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		pipex_error(9);
	close(fd[1]);
}

void	launch_second_child(char **av, int *fd)
{
	int	output_fd;

	close(fd[1]);
	output_fd = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (output_fd == -1)
		pipex_error(2);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		pipex_error(9);
	close(fd[0]);
	if (dup2(output_fd, STDOUT_FILENO) == -1)
		pipex_error(9);
	close(output_fd);
}