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

int	is_valid(int *board, int x, int y)
{
	int i = 0;
	while (i < x)
	{
			if (y == board[i])
					return (0);
			else if ((ft_abs(i - x)) == (ft_abs(board[i] - y)))
					return (0);
			i++;
	}
	return (1);
}

void	n_queens(int *board, int x, int size)
{
		int i = 0;
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
		if (ac != 2)
				return (1);
		int size = atoi(av[1]);
		int board[size];
		n_queens(board, 0, size);
		return (0);
}
