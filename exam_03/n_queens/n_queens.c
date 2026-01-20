/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmegon <carmegon@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:27:39 by carmegon          #+#    #+#             */
/*   Updated: 2026/01/20 21:45:55 by carmegon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	print_sol(int *board, int size)
{
	int i = 0;

	while (i < size)
	{
		fprintf(stdout, "%d", board[i]);
		if (i < (size - 1))
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

int	is_valid(int *board, int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (y == board[i])
			return (0);
		else if ((abs(i - x) == (abs(board[i] - y))))
			return (0);
		i++;
	}
	return (1);
}

void	n_queens(int *board, int x, int size)
{
	int	i;

	i = 0;
	if (x == size)
	{
		print_sol(board, size);
		return ;
	}
	while (i < size)
	{
		if (is_valid(board, x, i))
		{
			board[x] = i;
			n_queens(board, x + 1, size);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	//int i = 0;
	
	if (ac != 2)
		return (0);
	int size = atoi(av[1]);
	int board[size];
	n_queens(board, 0, size);
	return (0);
}
