#include <unistd.h>

void ft_union(char *s1, char *s2)
{
	int i = 0;
	while (s1[i])
	{
		unsigned char c = s1[i];
		if (s2[i] == 0)
		{
			write(1, &c, 1);
			s2[c] = 1;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	char s2[255] = {0};
	if (ac == 3)
	{
		ft_union(av[1], s2);
		ft_union(av[2], s2);
	}
	write(1,"\n", 1);
	return (0);
}
