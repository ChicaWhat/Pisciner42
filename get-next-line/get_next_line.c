
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:17:33 by carmegon          #+#    #+#             */
/*   Updated: 2025/06/03 18:47:51 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
	The firts ft read the fd and start to include the info in the stash.
*/

#include "get_next_line.h"

char    *read_line(int fd, char *stash)
{
    char	*str;
    ssize_t	bytes_read;
    
    if (!stash)
	{
		stash = malloc(1 * sizeof(char));
		if (!stash)
				return (NULL);
	}
	stash[0] = '\0';
	printf("AQUÍ MI STASH VALE: %s\n", stash);
	bytes_read = BUFFER_SIZE;
	while(bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		str = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!str)
			return (NULL);
		bytes_read = read(fd, str, BUFFER_SIZE);
		printf("[BYTES LEIDOS: %zd]\n", bytes_read);
		str[bytes_read] = '\0';
		stash = ft_strjoin(stash, str);
		free(str);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
 	stash = read_line(fd, stash);
	printf("Mi linea en bruto es esta: %s\n", stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	line = extract_line(stash);
	printf("Mi linea depurada es: %s\n", line);
/* 	
	!La estatica que contiene la linea en crudo de mi funcion read
	?stash = read_line(fd, stash);
	!En esta auxiliar meto la linea desde la posicion 0 hasta el /n
	?line = extract_line(stash);
	!Aqui vuelvo a llamar a mi variable estatica con los restos desde el /n hasta lo que leyo en mi funcion read gracias al BUFFER_SIZE
	?stash = update_line(buffer); 
*/
//! Mi return tiene que devolver LINE, pero por ahora va a devolver
//! stash para ir viendo qué me retorna mi funcion.
	return (line);
}
char	*extract_line(char *stash)
{
	char	*line = NULL;
	int	i;
	//int	len_stash;
	//len_stash = ft_strlen(stash);
	if (!stash)
		return (NULL);
	i = 0;
	printf("[Mi linea antes de entrar al bucle de extrac_line es: %s]\n", stash);
	while(stash[i] && stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			line = ft_strchr(stash, '\n');
			printf("[Mi linea despues de pasarle strchr es: %s]\n", line);
/* 			line = ft_substr(stash, 0, stash[i]);
			if (!line)
				return (NULL); */
		}
/* 		else
		{
			line = ft_strchr(stash, '\0');
			line = ft_substr(stash, stash[i], stash[len_stash]);
			if (!line)
				return (NULL);
		} */
		i++;
	}
	return (line);
}
int	main(void)
{
		int	fd;
		char	*line;

		fd = open("archivo.txt", O_RDONLY);
		line = NULL;
		printf("[AQUÍ MI LINEA VALE: %s]\n", line);
		while ((line = get_next_line(fd)) != NULL)
		{
				printf("[LÍNEA OBTENIDA DEL MAIN: %s]\n", line);
				free(line);
		}
/* 		line = get_next_line(fd);
		printf("[LÍNEA OBTENIDA DEL MAIN: %s]\n", line);
		free(line); */
		close(fd);
		return (0);
}
