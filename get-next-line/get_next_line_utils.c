/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:37:08 by carmegon          #+#    #+#             */
/*   Updated: 2025/06/06 17:41:27 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *stash, char *str)
{
	char	*new_stash;
	size_t	len_new;
	size_t	i;
	size_t	len_stash;

	i = 0;
	len_new = ft_strlen(str) + ft_strlen(stash) + 1;
	new_stash = (char *)malloc(len_new * sizeof(char));
	if (!new_stash)
		return (NULL);
	while (stash[i] != '\0')
	{
		new_stash[i] = stash[i];
		i++;
	}
	len_stash = ft_strlen(stash);
	i = 0;
	while (str[i] != '\0')
	{
		new_stash[len_stash + i] = str[i];
		i++;
	}
	new_stash[len_new] = '\0';
	/* 
		Aqui vamos a dejar comentado un free, porque ni idea
		de si lo voy a necesitar o no
		free(stash);
	*/
	return (new_stash);
}
size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/* 
	No se si la tengo que usar o no, pero aqui la dejo
char	*ft_strdup(char *stash)
{
	int		i;
	int		len_stash;

	stash = (char *)malloc(1 * sizeof(char));
	if (!stash)
		return (0);
	i = 0;
	while (stash[i])
	{
		stash[i] = s[i];
		i++;
	}
	stash[i] = '\0';
	return (stash);
} */
char	*ft_substr(char *stash, unsigned int start, size_t len)
{
	char			*line;
	unsigned int	i;

	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[start] && i < len)
	{
		line[i] = stash[start];
		i++;
		start++;
	}
	line[i] = '\0';
	return (line);
}
char	*ft_strchr(char *stash, char c)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == c)
		{
			line = &stash[i + 1];
			return (line);
		}
		i++;
	}
/* 	if (cast_c == '\0')
	{
		aux = (char *)&stash[i];
		return (aux);
	}
	else */
	return (NULL);
}
