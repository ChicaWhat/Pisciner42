#include <unistd.h>
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
		printf("%d", board[i]);
		if (i < (size - 1))
			printf(" ");
		i++;
	}
	printf("\n");
}

int	is_valid(int *board, int y, int x)
{
	int prev_y = 0;
	while (prev_y < y)
	{
		if (x == board[prev_y])
			return (0);
		else if ((ft_abs(y - prev_y)) == (ft_abs(x - board[prev_y])))
			return (0);
		prev_y++;
	}
	return (1);
}

void	n_queens(int *board, int y, int size)
{
	int x = 0;
	if (y == size)
	{
		print_sol(board, size);
		return ;
	}
	while (x < size)
	{
		if (is_valid(board, y, x))
		{
			board[y] = x;
			n_queens(board, y + 1, size);
		}
		x++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int size = atoi(av[1]);
	int board[size];
	n_queens(board, 0, size);
}










