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
    int res;

    i = 0;
    if (n == 0)
    {
        res = 0;
        return (res);
    }
    
    while (i < n && (s1[i] == s2[i]))
    {
        i++;
    }
    if (i < n)
    {
        res = s1[i] - s2[i];
    }
    else 
    {
        res = 0;
    }
    return (res);
}