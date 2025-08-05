#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_count(int nb)
{
		int count = 0;
		if (nb < 0)
				count++;
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
		int nb = nbr;
		int i = 0;
		char *str = malloc(len + 1 * sizeof(char));
		str[len] = '\0';
		if (nbr < 0)
		{
				str[0] = '-';
				i++;
		}
		while (i < len)
		{
			if (nbr >= 10)
					nb = nbr / 10;
			str[i] = nb % 10 + '0';
			i++;
		}
		return (str);
}

int main(int ac, char **av)
{
		(void)ac;
		(void)av;
		int nb = 123;
		char *num  = ft_itoa(nb);
		printf("Esta es mi cadena: %s\n", num);
		return (0);
}
