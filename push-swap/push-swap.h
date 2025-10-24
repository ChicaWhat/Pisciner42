/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:43:56 by carmegon          #+#    #+#             */
/*   Updated: 2025/10/17 13:43:56 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"


int	    ft_digit_space(char c);
int     ft_sign(char *str);
int     ft_no_repeat(char **list);
int     is_order(char **list);
long     ft_atol(char *str);
char    *ft_one_argv(char **av);
char    **ft_split_argv(int ac, char **av);
int     ft_is_valid(int ac, char **av);
void    ft_parsing(int ac, char **av);
void    ft_error(void);
void    ft_error(void);

#endif