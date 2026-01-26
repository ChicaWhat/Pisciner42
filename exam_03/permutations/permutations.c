#include "permutations.h"

//Creo variable global aqui
int 	size;

char *bubble_sort(char *s)
{
	int i = 0;
	char aux;
	int len = size;

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

void	permutations(char *res, int pos, int *aux, char *s)
{
	int i = 0;
	if (pos == size)
	{
		puts(res);
	}
	// Utilizo el iterador i para el array de int aux y el array s porque es lo
	// que estoy usando para recorrer la cadena orinal. Asi se cuando he impreso
	// ya un caracter o cuando aun no lo he hecho.
	while (i < size)
	{
		if (aux[i] == 0)
		{
			aux[i] = 1;
			res[pos] = s[i];
			permutations(res, pos + 1, aux, s);
			aux[i] = 0;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	size = strlen(av[1]);
	char *res = (char *)malloc(size + 1* sizeof(char));
	res[size] = '\0';
	//int pos = 0;
	int *aux = (int *)calloc(size, sizeof(int));

	if (ac != 2)
		return (1);
	bubble_sort(av[1]);
	permutations(res, 0, aux, av[1]);
	free(res);
	free(aux);
	return (0);
}