/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_av.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:54:00 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/29 16:54:00 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// --- Function to unify all **av into a single array ---//
char	*ft_one_argv(char **av)
{
	char	*res;
	char	*temp;
	int		i;

	res = ft_calloc(1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (ft_free_all(NULL, res, NULL));
		temp = res;
		res = ft_strjoin(res, av[i]);
		free(temp);
		if (!res)
			ft_error();
		temp = res;
		res = ft_strjoin(res, " ");
		free(temp);
		if (!res)
			ft_error();
		i++;
	}
	return (res);
}

//--- Function to split the single av created previously ---//
char	**ft_split_argv(char *one_av)
{
	char	**list;

	if (!one_av)
		return (NULL);
	list = ft_split(one_av, ' ');
	if (!list)
	{
		free(one_av);
		ft_error();
	}
	free(one_av);
	return (list);
}

//--- Function to calculate the size of the list ---//
int	list_size(char **list_num)
{
	int	i;

	i = 0;
	while (list_num[i])
		i++;
	return (i);
}

//--- Function to transform char** into long* ---//
long	*ft_convert_to_long_array(char **list, int size)
{
	int		i;
	long	*long_array;

	i = 0;
	long_array = malloc(size * sizeof(long));
	if (!long_array)
	{
		ft_free_all(list, NULL, NULL);
		return (NULL);
	}
	while (i < size)
	{
		long_array[i] = ft_atol(list[i]);
		i++;
	}
	return (long_array);
}
