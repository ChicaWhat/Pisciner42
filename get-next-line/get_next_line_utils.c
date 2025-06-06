/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:37:08 by carmegon          #+#    #+#             */
/*   Updated: 2025/06/06 16:42:41 by carmegon         ###   ########.fr       */
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
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	unsigned int	i;

	if (start > ft_strlen(s))
	{
		sub_s = ft_calloc(1, 1);
		return (sub_s);
	}
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		sub_s[i] = s[start];
		i++;
		start++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
char	*ft_stashchr(const char *s, int c)
{
	char	cast_c;
	char	*aux;
	int		i;

	cast_c = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cast_c)
		{
			aux = (char *)&s[i];
			return (aux);
		}
		i++;
	}
	if (cast_c == '\0')
	{
		aux = (char *)&s[i];
		return (aux);
	}
	else
		return (NULL);
}
