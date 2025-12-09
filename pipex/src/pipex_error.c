/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:02:18 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/09 12:31:12 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	pipex_error(int error_code)
{
	ft_putstr_fd(RED, 2);
	if (error_code == 126)
	{
		write(2, "\033[31mPipex: permission denied\033[0m\n", 35);
		exit(2);
	}
	else if (error_code == 127)
	{
		write(2, "\033[31mPipex: command not found\033[0m\n", 35);
		exit(2);
	}
	else if (error_code == 24)
	{
		ft_putstr_fd(strerror(error_code), 2);
		write(1, "\n", 1);
		ft_putstr_fd(RESET, 2);
		exit(2);
	}
	else
	{
		ft_putstr_fd(strerror(error_code), 2);
		write(1, "\n", 1);
		ft_putstr_fd(RESET, 2);
		exit(2);
	}
}

void	path_not_found(char **envp)
{
	envp = NULL;
	ft_putstr_fd(RED, 2);
	write(2, "Error: PATH not found\n", 22);
	ft_putstr_fd(RESET, 2);
	exit(2);
}
