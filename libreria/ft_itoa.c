/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:57:26 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/11 21:38:23 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_numbers(int num)
{
	int	result;

	result = 0;
	if (num < 0)
		result++;
	while (num != 0)
	{
		num /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len_num;
	int		sign;

	len_num = ft_count_numbers(n);
	sign = 1;
	result = (char *)malloc((len_num + 1) * sizeof(char));
	if (!result)
		return (NULL);
}
