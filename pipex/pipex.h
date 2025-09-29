/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:03:48 by carmegon          #+#    #+#             */
/*   Updated: 2025/09/29 20:24:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- The "fcntl.h" library is for using the constants required by the
	open() function.
	- The "sys/wait.h" library is for using the pid_t type. 
*/

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft/libft.h"

# ifndef RED
#  define RED "\033[31m"
# endif
# ifndef RESET
#  define RESET "\033[0m"
# endif

void	pipex_error(int error_code);
char	**get_path(char **env);
void	ft_free_all(char **list, char *str);
char	*find_command_path(char **path_list, char *command);
int count_sigle_quotes(char *str, char c);
char **filter_array(char **command);
char **check_commands(char **av);

#endif
