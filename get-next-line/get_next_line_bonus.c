/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:17:33 by carmegon          #+#    #+#             */
/*   Updated: 2025/06/16 17:31:01 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *stash)
{
	char	*str;
	ssize_t	bytes_read;

	if (!stash)
	{
		stash = malloc(1 * sizeof(char));
		stash[0] = '\0';
		if (!stash)
			return (ft_free(&stash));
	}
	bytes_read = BUFFER_SIZE;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		str = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!str)
			return (NULL);
		bytes_read = read(fd, str, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(&stash), ft_free(&str));
		str[bytes_read] = '\0';
		stash = ft_strjoin(stash, str);
		ft_free(&str);
	}
	return (stash);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
	{
		stash = NULL;
		return (NULL);
	}
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	if (!line)
	{
		ft_free(&stash);
		ft_free(&line);
	}
	return (line);
}

char	*ft_update_line(char *stash)
{
	char	*aux;
	int		i;

	i = 0;
	if (!stash[i])
	{
		stash = NULL;
		return (NULL);
	}
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	aux = ft_substr(stash, i, ft_strlen(stash + i));
	if (!aux)
	{
		ft_free(&stash);
		ft_free(&aux);
	}
	ft_free(&stash);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_read_line(fd, stash[fd]);
	if (!stash[fd] || stash[fd][0] == '\0')
		return (ft_free(&stash[fd]));
	line = ft_extract_line(stash[fd]);
	if (!line)
		return (NULL);
	stash[fd] = ft_update_line(stash[fd]);
	if (!stash[fd])
		return (NULL);
	return (line);
}

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("archivo.txt", O_RDONLY);
	//fd = open("oneline.txt", O_RDONLY);
	//fd = open("vacio.txt", O_RDONLY);
	while ((line = ft_get_next_line(fd)) != NULL)
	{
		printf("LÍNEA OBTENIDA DEL MAIN: %s]", line);
		free(line);
	}
	close(fd);
	return (0);
} */
