/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:03:48 by carmegon          #+#    #+#             */
/*   Updated: 2025/12/09 21:42:19 by carmegon         ###   ########.fr       */
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

void	ft_daddy(char **av, char **envp, int *fd);
void	launch_first_child(char **av, int *fd);
void	launch_second_child(char **av, int *fd);
void	ft_first_child(char **av, char **envp, int *fd);
void	ft_second_child(char **av, char **envp, int *fd);
void	pipex_error(int error_code);
void	path_not_found(char **envp);
char	**get_path(char **env);
char	*get_command_path(char **path_list, char *command);
void	ft_free_all(char **list1, char **list2, int flag);
char	*find_command_path(char **path_list, char *command);
char	**check_commands(char **av);

#endif
