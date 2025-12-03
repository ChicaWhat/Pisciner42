/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:02:24 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/02 21:11:43 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **envp)
{
	char	**path;
	char	*command;

	(void)ac;
	path = get_path(envp);
	command = find_command_path(path, av[1]);
	if (command)
		ft_printf("%s\n", command);
	ft_free_all(path, command);
	return (0);
}
