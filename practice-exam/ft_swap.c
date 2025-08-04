#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
		int	aux;

		aux = *a;
		*a = *b;
		*b = aux;
}

int	main(void)
{
		int a = 1;
		int b = 2;
		printf("a vale: %d\n b vale: %d\n", a, b);
		ft_swap(&a, &b);
		printf("a vale: %d\n b vale: %d\n", a, b);
		return (0);
}
