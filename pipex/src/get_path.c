/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:20:26 by carmegon          #+#    #+#             */
/*   Updated: 2025/09/26 21:21:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void ft_free_all(char **list, char *str)
{
	int i;

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

char **get_path(char **env)
{
	char *path_env;
	char **path_list;
	int i;

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
	ft_free_all(path_list, NULL);
	return (NULL);
}

char *find_command_path(char **path_list, char *command)
{
	char *full_path;
	char *new_path;
	int i;

	i = 0;
	while (path_list[i])
	{
		new_path = ft_strjoin(path_list[i], "/");
		full_path = ft_strjoin(new_path, command);
		if (!full_path)
		{
			ft_free_all(path_list, new_path);
			return (NULL);
		}
		free(new_path);
		if (access(full_path, X_OK) == 0)
			break;
		free(full_path);
		i++;
	}
	if (!path_list[i])
	{
		ft_free_all(path_list, NULL);
		pipex_error(127);
	}
	return (full_path);
}
