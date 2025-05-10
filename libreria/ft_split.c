/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:40:46 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/10 16:16:39 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_counter(char const *str, char c)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	flag = 1;
	words = 0;
	while (str[i])
	{
		if (str[i] == c)
			flag = 1;
		if (str[i] != c && flag)
		{
			flag = 0;
			words++;
		}
		i++;
	}
	return (words);
}

static void	ft_fill_array(char **list, char const *str, int w_count, char c)
{
	int	i;
	int	word_len;

	i = 0;
	word_len = 0;
	while (w_count && str && str[word_len])
	{
		while (str[word_len] != c && str[word_len])
		{
			word_len++;
		}
		list[i] = ft_substr(str, 0, word_len);
		str = str + word_len + 1;
		while (*str == c)
			str++;
		word_len = 0;
		i++;
		w_count--;
	}
	list[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		w_count;
	char	*wordtrim;
	char	**list;

	w_count = ft_word_counter(s, c);
	wordtrim = ft_strtrim(s, &c);
	if (!wordtrim)
		return (NULL);
	list = malloc((w_count + 1) * sizeof(char *));
	if (!list)
	{
		free (wordtrim);
		return (NULL);
	}
	ft_fill_array(list, wordtrim, w_count, c);
	free(wordtrim);
	return (list);
}
