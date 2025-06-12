/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:17:33 by carmegon          #+#    #+#             */
/*   Updated: 2025/06/12 19:25:10 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	The firts ft read the fd and start to include the info in the stash.

#include "get_next_line.h"

char	*read_line(int fd, char *stash)
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
		if (bytes_read < 0 || str[0] == '\0')
			return (ft_free(&str), ft_free(&stash));
		str[bytes_read] = '\0';
		stash = ft_strjoin(stash, str);
		ft_free(&str);
	}
	return (stash);
}

char	*extract_line(char *stash)
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
		return (NULL);
	}
	return (line);
}

char	*update_line(char *stash)
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
		return (NULL);
	}
	ft_free(&stash);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash || stash[0] == '\0')
		return (ft_free(&stash));
	line = extract_line(stash);
	if (!line)
		return (NULL);
	stash = update_line(stash);
	if (!stash)
		return (NULL);
	return (line);
}
/*int	main(void)
{
		int	fd;
		char	*line;

		fd = open("archivo.txt", O_RDONLY);
		printf("%s", get_next_line(5));
		while ((line = get_next_line(100)) != NULL)
		{
				printf("LÍNEA OBTENIDA DEL MAIN: %s]", line);
				free(line);
		}
		close(fd);
		return (0);
}*/
