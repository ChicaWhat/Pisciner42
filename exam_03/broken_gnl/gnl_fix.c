/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_fix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:16:50 by carmegon          #+#    #+#             */
/*   Updated: 2026/01/19 17:11:52 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(char *s, int c)
{
	int	i = 0;
//! FALLO 1. Condicion del bucle.
	while (s[i] && s[i] != c) // Mientras tenga algo que recorre y además s[i] sea distinto del caracter que me pasan.
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}
//! FALLO 2. Condicion del bucle tambien.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
    // Aqui cambiamos el (--n > 0) por lo que tengo ahora declarado en el bucle. (n--)
    //Además, se quita el n - 1, porque sino estoy perdiendo un valor de lo que necesito copiar de src a dest!
	size_t i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

//! FALLO 3. Debo de proteger la funcion de punteros NULL. Por eso, me falta una comprobacion antes de entrar en el while. 
size_t	ft_strlen(char *s)
{
	size_t	res = 0;
/* 
	?Existe el puntero?? (es NULL o no?) -> !s
	?Tiene contenido -> !*s
*/
	if (!s)
		return (0);

	while (*s)
	{
		s++;
		res++;
	}
	return (res);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = '\0';
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		return (ft_memcpy(dest, src, n));
	else if (dest == src)
		return (dest);
	else
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;
	char	*tmp = ft_strchr(b, '\n');
	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		int read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		b[read_ret] = 0;
		if (read_ret == 0)
		{
			if (*ret)
				return (ret);
			free(ret);
			return (NULL);
		}
		tmp = ft_strchr(b, '\n');
	}
	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	memmove(b, tmp + 1, ft_strlen(tmp + 1));
	return (ret);
}
