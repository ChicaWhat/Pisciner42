#include <stdio.h>

int main(int ac, char **av)
{
		char *fruits[] = {"manzana", "kiwi", "platano", "uva"};
		char **ptr = fruits;
		//int i = 1;
		int j = 0;
		(void)av;
		(void)ac;

		printf("Mi posicion 0 del array vale: [%s]\n", (*ptr));
		printf("Posicion 0 del array hecho con indexador: [%s]\n", ptr[j]);
		printf("####################################################\n");
		printf("El primer caracter de mi primer elemento es: [%c]\n", (**ptr));
		return (0);
}
