/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:53:18 by carmegon          #+#    #+#             */
/*   Updated: 2025/09/23 16:14:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (*big && len >= ft_strlen(little))
	{
		if (*big == *little && ft_strncmp(big, little, ft_strlen(little)) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
