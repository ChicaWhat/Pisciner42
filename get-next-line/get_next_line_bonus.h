/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:54:20 by carmegon          #+#    #+#             */
/*   Updated: 2025/06/16 17:28:55 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *str);
char	*ft_extract_line(char *stash);
char	*ft_update_line(char *stash);
char	*ft_strjoin(char *stash, char *str);
size_t	ft_strlen(char *s);
char	*ft_substr(char *stash, unsigned int start, size_t len);
char	*ft_strchr(char *stash, char c);
char	*ft_free(char **str);

#endif
