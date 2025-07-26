#include <stdio.h>

int main(int ac, char **av)
{
	char *fruits[] = {"kiwi", "pera", "manzana", "platano"};
	char **ptr = fruits;
	int i = 0;
	(void)ac;
	(void)av;
	printf("Mi doble puntero apunta al primer caracter del primer argumento: [%c]\n", **ptr);
	printf("Mi doble puntero apunta al primer caracter del segundo argumento: [%c]\n", (*ptr[1]));
	printf("Mi doble puntero apunta al primer caracter del tercer av: [%c]\n", *ptr[2]);
	printf("Mi doble puntero y el primer caracter del cuarto av: [%c]\n", *ptr[3]);
	while (**ptr != '\0')
	{
		printf("Este es mi array completo: [%s]\n", (*ptr));
		ptr++;
	}
	while (*ptr[i] != '\0')
	{
		printf("La letra de cada palabra de mi array: [%c]\n", **ptr);
		(*ptr)++;
	}
	return (0);
	}
