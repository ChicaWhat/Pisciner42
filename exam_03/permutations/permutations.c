#include "permutations.h"

//Creo variable global aqui
int 	size;

char *bubble_sort(char *s)
{
	int i = 0;
	char aux;
	int len = strlen(s);

	while (i <= len)
	{
		i = 0;
		while (i < len - 1)
		{
			if (s[i] > s[i + 1])
			{
				aux = s[i];
				s[i] = s[i + 1];
				s[i + 1] = aux;
			}
			i++;
		}
		len--;
	}
	return (s);
}

void	permutations(char *res, int pos, int *aux)
{
	int i = 0;
	if (pos == size)
	{
		puts(res);
	}
	while (i < size)
	{
		aux[pos] = 1;

	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("%s", bubble_sort(av[1]));
	return (0);
}