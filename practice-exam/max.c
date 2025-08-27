#include <stdlib.h>
#include <stdio.h>

int max(int *tab, unsigned int len)
{
		int aux;
		unsigned int i = 0;

		if (!tab || len == 0)
				return (0);

		aux = tab[0];
		while (i < len)
		{
			if (aux < tab[i])
					aux = tab[i];
			i++;
		}
		return (aux);
}

int main(int ac, char **av)
{
		(void)ac;
		(void)av;
		int tab[] = {3, 9, 2, 15, 7, 10};
		int len = 6;

		if (ac == 3)
				printf("%d\n", max(&tab[5], len));
		return (0);
}
