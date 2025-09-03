#include <unistd.h>

int ft_isspace(char c)
{
		return (c == 32 || c == '\t');
}

int ft_strlen(char *str)
{
		int i = 0;
		while (str[i])
				i++;
		return (i);
}

int main(int ac, char **av)
{
		int i = 0;
		int len = ft_strlen(av[1]) - 1;
		if (ac != 2)
		{
				write(1, "\n", 1);
				return (1);
		}
		while (len >= 0)
		{
			while (len >= 0 && ft_isspace(av[1][len]))
					len--;
			i = len;
			while (len >= 0 && !ft_isspace(av[1][len]))
					len--;
			if (len == 0)
			{
					write(1, &av[1][len], (i - len + 1));
					av[1][len] = '\0';
			}
			else
			{

					write(1, &av[1][len + 1], (i - len));
					write(1, " ", 1);
					av[1][len + 1] = '\0';
			}
		}
		write(1, "\n", 1);
		return (0);
}
