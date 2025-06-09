
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
	bytes_read = BUFFER_SIZE;
	while(bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		str = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!str)
			return (NULL);
		bytes_read = read(fd, str, BUFFER_SIZE);
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
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	line = extract_line(stash);
	stash = update_line(stash);
	return (line);
}
char	*extract_line(char *stash)
{
	char	*line;
	int	i;

	if (!stash)
		return (NULL);
	i = 0;
	while(stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	if (!line)
	{
		free(stash);
		free(line);
		return (NULL);
	}
	return (line);
}

char	*update_line(char *stash)
{
	char	*aux;
	int	i;
	//int	len_stash;

	//en_stash = ft_strlen(stash);
	if(!stash)
		return (NULL);
	i = 0;
	while(stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	aux = ft_substr(stash, i, ft_strlen(stash + i));
	printf("Mi nuevo stash es: %s\n", aux);
	if (!aux)
	{
		free(stash);
		free(aux);
		return (NULL);
	}
	free(stash);
	stash = aux;
	return (stash);
}
int	main(void)
{
		int	fd;
		char	*line;

		fd = open("archivo.txt", O_RDONLY);
		//line = NULL;
		//line = get_next_line(fd);
		while ((line = get_next_line(fd)) != NULL)
		{
				printf("[LÍNEA OBTENIDA DEL MAIN: %s]\n", line);
				free(line);
		}
		close(fd);
		return (0);
}
