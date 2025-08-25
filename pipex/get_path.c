/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:20:26 by carmegon          #+#    #+#             */
/*   Updated: 2025/08/25 23:53:16 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char	*path_env;
	char	**path_list;
	char	*final_root;
	char	*new_path;
	int		i;

	i = 0;
	while (env[i])
	{
			if (ft_strnstr(env[i], "PATH=", 5) != 0)
			{
				path_env = env[i] + 5;
				path_list = ft_split(path_env, ':')
				return (path_list);
			}
			i++;
	}
	return (NULL);
	//path_list = ft_split(path_env, ':');
	//i = 0;
	//while (path_list[i])
	//{
	//	new_path = ft_strjoin(path_list[i], "/");
	//	final_root = ft_strjoin(new_path, command);
	//	free(new_path);
	//	i++;
	//}
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
	}
}
