/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:03:48 by carmegon          #+#    #+#             */
/*   Updated: 2025/08/10 16:22:28 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The "fcntl.h" library is for using the constants required by the
	open() function.
*/

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include  <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//int open(char *nameFile, )

#endif
