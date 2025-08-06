#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_count(int nb)
{
		int count = 0;
		if (nb <= 0)
				count++;
		nb = -nb;
		while (nb > 0)
		{
				nb = nb / 10;
				count++;
		}
		return (count);
}

char *ft_itoa(int nbr)
{
		int len = ft_count(nbr);
		//int count = 0;
		long nb = nbr;
		//int i = 0;
		char *str = malloc(len + 1 * sizeof(char));
		str[len] = '\0';
		if (nb < 0)
				str[0] = '-';
		if (nb < 0)
				nb *= -1;
		//nb *= -1;
		while (nb != 0)
		{
			str[len - 1] = nb % 10 + '0';
			nb /= 10;
			len--;
		}
		return (str);
}

int main(int ac, char **av)
{
		(void)ac;
		(void)av;
		long nb = 1233409;
		char *num  = ft_itoa(nb);
		printf("Esta es mi cadena: %s\n", num);
		return (0);
}
