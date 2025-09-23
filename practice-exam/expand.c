#include <unistd.h>
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

int is_space(char c)
{
	if (c == 32 || c == '\t')
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	int i = 0;
	int j;
	//int len = ft_strlen(av[1]);
	char *str = av[1];
	if (ac == 2)
	{
		while (str[i] && str[0] != '\0')
		{
			while (is_space(str[i]))
				i++;
			while (!(is_space(str[i])) && str[i])
			{
				write(1, &str[i], 1);
				i++;
			}
			j = i;
			while (is_space(str[j]))
				j++;
			if (str[j])
				write(1, "   ", 3);
			i = j;
		}
	}
	write(1, "\n", 1);
	return (0);
}
