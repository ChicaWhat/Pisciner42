/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 22:25:41 by carmegon          #+#    #+#             */
/*   Updated: 2026/01/19 17:11:01 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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

int main(void)
{
	int fd;
	char *line;
	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
