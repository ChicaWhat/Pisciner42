#include <stdio.h>

int ft_strlen(char *str)
{
		int i = 0;

		while (str[i])
		{
				i++;
		}
		return (i);
}

char *ft_strrev(char *str)
{
		int i = 0;
		char aux;
		int len = ft_strlen(str) - 1;

		while (i <= len)
		{
				aux = str[len];
				str[len] = str[i];
				str[i] = aux;
				i++;
				len--;
		}
		return (str);
}

int main(int ac, char **av)
{
		//int i = 0;
		if (ac == 2)
		{
				printf("%s\n", ft_strrev(av[1]));
		}
		return (0);
}
