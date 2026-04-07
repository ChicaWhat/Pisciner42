#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size;

char *bubble_sort(char *s)
{
	int i = 0;
	int len = size;
	char aux;
	while (i <= len)
	{
		while (i < (len - 1))
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

void	permutations(char *res, int *aux, int pos, char *s)
{
	int i = 0;
	if (pos == size)
		puts(res);
	while (i < size)
	{
		if (aux[i] == 0)
		{
			aux[i] = 1;
			res[pos] = s[i];
			permutations(res, aux, pos + 1, s);
			aux[i] = 0;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	size = strlen(av[1]);
	char *res = (char *)malloc(size + 1 * sizeof(char));
	if (!res)
		return (1);
	res[size] = '\0';
	int	*aux = calloc(size, sizeof(int));
	if (!aux)
		return (1);
	bubble_sort(av[1]);
	permutations(res, aux, 0, av[1]);
	free(res);
	free(aux);
	return (0);
}
