/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:05:30 by marvin            #+#    #+#             */
/*   Updated: 2025/04/30 22:05:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
//    size_t j;
    size_t res;

    i = 0;
//    j = 0;
    if (n == 0)
    {
        res = 0;
        return (res);
    }
    
    while (s1[i] != '\0' && s2[i] != '\0' && (i < n))
    {
        if (s1[i] != s2[i])
        {
            res = s1[i] - s2[i];
            return (res);
        }
        i++;
    }
    res = 0;
    return (res);
}