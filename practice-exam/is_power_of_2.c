#include <stdio.h>
#include <stdlib.h>

/*
	Hay que averiguar si el numero que nos pasan por parametros es potencia de
	2. Una potencia es el resultado de multiplicar el numero X POR SI MISMO una
	cantidad especifica de veces.
	Para ello, me creo una variable con valor 1 y voy multiplicando esta variable
	x2. Si el numero que consigo es exactamente igual al numero que me han pasado
	por parámetros, entonces es potencia de 2, sino no lo es.
*/
int is_power_of_2(unsigned int n)
{
		unsigned int prueba = 1;

		while (prueba < n)
		{
				prueba *= 2;
				if (prueba == n)
						return (1);
		}
		return (0);
}

int main(int ac, char **av)
{
		if (ac == 2)
				printf("%d\n", is_power_of_2(atoi(av[1])));
		return (0);
}
