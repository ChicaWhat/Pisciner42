/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:01:59 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/09 12:28:14 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	count_sigle_quotes(char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	**filter_array(char **command)
{
	char	**new_array;

	new_array = ft_calloc(4, sizeof(char *));
	if (!new_array)
		return (NULL);
	new_array[0] = command[0];
	//printf("Este es new_array[0]: %s\n", new_array[0]);
	new_array[1] = command[1];
	//printf("Este es new_array[1]: %s\n", new_array[1]);
	new_array[2] = command[3];
	//printf("Este es new_array[2]: %s\n", new_array[2]);
	//ft_free_all(new_array, NULL);
	return (new_array);
}

/* char	**check_commands(char **av)
{
	int		count;
	char	**command_split;
	char	**new_array;

	count = count_sigle_quotes(*av, '\'');
	//printf("Esto es para saber cuantas comillas simples tengo: %d\n", count);
	if (count == 2)
	{
		command_split = ft_split(*av, '\'');
		command_split[0] = ft_strtrim(command_split[0], " ");
		command_split[2] = NULL;
		return (command_split);
	}
	else if (count == 4)
	{
		command_split = ft_split(*av, '\'');
		for (int j = 0; command_split[j]; j++)
			printf("Los comandos spliteados: [%s]\n", command_split[j]);
		command_split[0] = ft_strtrim(command_split[0], " ");
		new_array = filter_array(command_split);
		for (int x = 0; new_array[x]; x++)
			printf("Este es new_array completo en check_commands: %s\n", new_array[x]);
		ft_free_all(command_split, NULL);
		return (new_array);
	}
	else
	{
		command_split = ft_split(*av, ' ');
		return (command_split);
	}
} */

/* char	**check_commands(char **av)
{
	char	**command_split;

	command_split = ft_split(*av, ' ');
	return (command_split);
} */
