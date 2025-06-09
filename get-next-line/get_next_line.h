/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:54:20 by carmegon          #+#    #+#             */
/*   Updated: 2025/06/09 12:50:39 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char    *read_line(int fd, char *str);
char	*extract_line(char *stash);
char    *ft_strjoin(char *stash, char *str);
size_t  ft_strlen(char *s);
char    *ft_substr(char *stash, unsigned int start, size_t len);
char    *ft_strchr(char *stash, char c);

#endif
