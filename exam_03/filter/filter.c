#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strcmp(char *s1,char *s2, int n)
{
		int	i = 0;

		while ((s1[i] && s2[i]) && i < n)
		{
				if (s1[i] != s2[i])
						return (1);
				i++;
		}
		return (0);
}

int main(int ac, char **av)
{
		int i = 0;
		char *buf = (char *)malloc(9999 * sizeof(char));
		ssize_t byte;
		int j = 0;

		if (!buf)
		{
				perror("Error");
				return (1);
		}
		if (ac != 2 || av[1] == NULL || av[1][j] == '\0')
		{
			printf("Not av valid\n");
			return (1);
		}
		/*
			Sintaxis: fd: Desde donde voy a comenzar a leer.
			*buf: La direccion de memoria donde guardo lo que leo.
			count: la cantidad de caracteres que voy a leer de golpe.
		*/
		while ((byte = read(0, &buf[i], 1)) > 0 && &buf[i])
		{
			if (byte == -1)
			{
					perror("Error");
					return (1);
			}
			i++;
		}
		buf[i] = '\0';
		i = 0;
		j = 0;
		while (buf[i])
		{
			j = 0;
			if (ft_strcmp(&buf[i], av[1], strlen(av[1])) == 0)
			{
				while (av[1][j])
				{
					printf("*");
					j++;
				}
				i += strlen(av[1]) - 1;
			}
			else
				printf("%c", buf[i]);
			i++;
		}
		free(buf);
		return (0);
}
