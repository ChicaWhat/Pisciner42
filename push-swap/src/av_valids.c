/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_valids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:49:00 by carmegon          #+#    #+#             */
/*   Updated: 2025/11/29 16:49:00 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//--- Function to detect any non-numeric character ---//
int	ft_digit_space(char c)
{
	if (c == '+' || c == '-')
		return (0);
	else if (c >= 48 && c < 58)
		return (0);
	else
		return (1);
}

/* --- Function to check for non-numeric characters at the 
beginning and in the middle of av --- */
int	ft_sign(char *str)
{
	int	i;

	i = 0;
	if (!str[i] || str[i] == '\0')
		return (1);
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
			return (1);
		else if (ft_digit_space(str[i]))
			return (1);
		else if (ft_isdigit(str[i]) && (str[i + 1] == '+' || str[i + 1] == '-'))
			return (1);
		i++;
	}
	return (0);
}

//--- Function to check if there are no repeated arguments ---//
int	ft_no_repeat(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = i + 1;
		while (list[j])
		{
			if (ft_atol(list[i]) != ft_atol(list[j]))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

//--- Function to check if the arguments are already sorted ---//
int	is_order(char **list)
{
	int	i;
	int	j;

	i = 0;
	while ((list[i]))
	{
		j = i + 1;
		while ((list[j]))
		{
			if (ft_atol(list[i]) < ft_atol(list[j]))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
