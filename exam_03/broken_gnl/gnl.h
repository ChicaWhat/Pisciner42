/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:48:31 by carmegon          #+#    #+#             */
/*   Updated: 2026/03/24 19:01:35 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
#endif

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);
void	*ft_memcpy(void *dest, const void *src, int n);
int		str_append_mem(char **s1, char *s2, int size2);
int		str_append_str(char **s1, char *s2);
void	*ft_memmove(void *dest, const void *src, int n);

#endif