/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:39:18 by marvin            #+#    #+#             */
/*   Updated: 2025/04/30 21:39:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char    cast_c;
    char    aux;
    int i;
    int len_s = ft_strlen(s);

    cast_c = c;
    i = len_s;
    while (s[len_s] != '\0')
    {
        if (s[len_s] == cast_c)
        {
            aux = (char *)&s[len_s];
            return (aux);
        }
        i--;
    }
    if (cast_c == '\0')
    {
        aux = (char *)&s[len_s];
        return (aux);
    }
    else
        return (NULL);
}