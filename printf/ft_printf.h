/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:14:34 by carmegon          #+#    #+#             */
/*   Updated: 2025/05/28 10:28:16 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(char const *chain, ...);
int		ft_print_str(char *str);
int		ft_print_char(int c);
int		ft_print_nbr(int num);
int		ft_print_hex_top(unsigned int num);
int		ft_print_hex_bottom(unsigned long long num);
int		ft_print_ptr(void *ptr);
int		ft_print_uns(unsigned int num);

#endif
