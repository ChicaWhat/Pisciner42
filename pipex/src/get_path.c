/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:20:26 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/09 12:27:58 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free_all(char **list, char *str)
{
	int	i;

	i = 0;
	if (list)
	{
		while (list[i])
		{
			free(list[i]);
			i++;
		}
		free(list);
	}
	if (str)
		free(str);
}

char	**get_path(char **env)
{
	char	*path_env;
	char	**path_list;
	int		i;

	i = 0;
	path_list = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != 0)
		{
			path_env = env[i] + 5;
			path_list = ft_split(path_env, ':');
			return (path_list);
		}
		i++;
	}
	if (!path_list)
		return (NULL);
	ft_free_all(path_list, NULL);
	return (NULL);
}

char	*get_command_path(char **path_list, char *command)
{
	char	*full_path;

	if (access(command, X_OK) == 0)
		return (command);
	else
		full_path = find_command_path(path_list, command);
	if (!*path_list)
	{
		ft_free_all(path_list, NULL);
		pipex_error(127);
	}
	return (full_path);
}

char	*find_command_path(char **path_list, char *command)
{
	char	*full_path;
	char	*new_path;
	int		i;

	i = 0;
	while (path_list[i])
	{
		if (access(command, X_OK) == 0)
			return (command);
		else
		{
			new_path = ft_strjoin(path_list[i], "/");
			full_path = ft_strjoin(new_path, command);
			if (!full_path)
				return (ft_free_all(path_list, new_path), NULL);
			free(new_path);
			if (access(full_path, X_OK) == 0)
				break ;
			free(full_path);
		}
		i++;
	}
	return (full_path);
}

char	**check_commands(char **av)
{
	char	**command_split;

	command_split = ft_split(*av, ' ');
	return (command_split);
}
