#include <stdlib.h>
#include <stdio.h>

int max(int *tab, unsigned int len)
{
		int aux;
		unsigned int i = 1;

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
		int *tab = NULL;
		int len = 0;

		if (ac == 1)
				printf("%d\n", max(&tab[0], len));
		return (0);
}
