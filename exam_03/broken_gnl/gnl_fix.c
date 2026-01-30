/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_fix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 23:16:50 by carmegon          #+#    #+#             */
/*   Updated: 2026/01/30 12:32:59 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <stdlib.h>
#include <unistd.h>

//:%s/size_t/int

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
//! FALLO 2. Cambiamos el metodo de copiar.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
    // Aqui recreamos lo que hace la funcion de mempcy: copiar de izquierda a derecha.
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
// !FALLO 3. Si *s1 tiene contenido, entremos en esa primera llamada al memcpy.
// !Si no, pasamos directamente a la segunda llamada.
int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	if (*s1)
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
//! FALLO 4. Cambiamos las condiciones para recrear el comportamiento de la funcion de memmove y quitamos la llamada a la funcion strlen.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
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
//! FALLO 5. Dentro del bucle debemos de tener en cuenta si la variable estática ha leido 0 byes. 
//! Volvemos a llamar, al final del bucle, a la funcion strchr.
//! Antes del ultimo return debemos de copiar la ultima línea que sea del fd. Por eso debemos de llamar a memmove. 
char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;
	char	*tmp = ft_strchr(b, '\n');
	int		read_ret;
	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		read_ret = read(fd, b, BUFFER_SIZE);
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
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	return (ret);
}

int	main(void)
{
	int fd;
	char *line;
	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}



/* char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;
	char	*tmp;
	int read_ret;
	while (1)
	{
		tmp = ft_strchr(b, '\n');
		if (tmp)
			break ;
		if (!str_append_str(&ret, b))
			return (NULL);
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		b[read_ret] = 0;
		if (read_ret == 0)
		{
			ft_memmove(b, ret, ft_strlen(ret));
			free(ret);
			return (*b)? b : NULL;
		}
	}
	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	return (ret);
} */