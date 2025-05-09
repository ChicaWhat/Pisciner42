/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:40:46 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/09 22:45:45 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_counter(char *str, char c)
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

static void	ft_fill_array(char **list, char *str, int letter_count, char c)
{
	int	i;
	int	word_len;

	i = 0;
	word_len = 0;
	while (letter_count && str && str[i])
	{
		while (str[word_len] != c && str[word_len])
		{
			word_len++;
		}
		list[i] = ft_substr(str, 0, word_len)

	}
}













