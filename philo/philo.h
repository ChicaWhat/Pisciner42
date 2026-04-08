/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 21:47:44 by carmegon          #+#    #+#             */
/*   Updated: 2026/04/08 22:32:47 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int	is_digit(int c);
int	is_av_valid(char **av);
int	check_av(int ac, char **av);
int	ft_atoi(char *s);
int main(int ac, char **av);

#endif