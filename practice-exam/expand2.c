#include <unistd.h>

int is_space(char c)
{
	if (c == 32 || c == '\t')
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	int i = 0;
	//int j;
	char *str = av[1];
	if (ac == 2)
	{
		while (str[i])
		{
			while (is_space(str[i]))
				i++;
			while (!(is_space(str[i])) && str[i])
			{
				write(1, &str[i], 1);
				i++;
			}
			if (str[i] && str[++i])
				write(1, " ", 3);
		}
	}
	write(1, "\n", 1);
	return (0);
}
