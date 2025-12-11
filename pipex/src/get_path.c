/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:20:26 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/10 18:31:54 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free_all(char **list1, char **list2, int flag)
{
	int	i;

	i = 0;
	if (list1)
	{
		while (list1[i])
		{
			free(list1[i]);
			i++;
		}
		free(list1);
	}
	i = 0;
	if (list2)
	{
		while (list2[i])
		{
			free(list2[i]);
			i++;
		}
		free(list2);
	}
	if (flag)
		pipex_error(flag);
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
	if (!path_list || !path_list[0])
	{
		ft_free_all(path_list, NULL, 0);
		return (NULL);
	}
	ft_free_all(path_list, NULL, 0);
	return (NULL);
}

char	*get_command_path(char **path_list, char *command)
{
	char	*full_path;

	if (!command)
		return (NULL);
	if (access(command, X_OK) == 0)
		return (command);
	else
		full_path = find_command_path(path_list, command);
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
		new_path = ft_strjoin(path_list[i], "/");
		full_path = ft_strjoin(new_path, command);
		free(new_path);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	**check_commands(char **av)
{
	char	**command_split;

	command_split = ft_split(*av, ' ');
	if (!command_split || !command_split[0])
	{
		ft_free_all(command_split, NULL, 0);
		return (NULL);
	}
	return (command_split);
}
