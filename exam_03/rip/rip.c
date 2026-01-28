#include <stdio.h>

int	open_and_close(char *s)
{
	int	o = 0;
	int	c = 0;
	int	i = 0;

	while (s && s[i])
	{
		if (s[i] == '(')
			o++;
		if (s[i] == ')')
		{
			if (o > 0)
				o--;
			else
				c++;
		}
		i++;
	}
	return (o + c);
}

void	solve(char *s, int i, int total)
{
	//int i = 0;
	int	rm = 0;

	if (total == 0 || rm == total)
	{
		puts(s);
		return ;
	}

	while (s[i])
	{
		s[i] = s[i];
		if (rm <= total)
		{
			solve(s, i + 1, total);
			rm++;
		}
		else
		{
			s[i] = ' ';
			solve(s, i + 1, total);
			rm++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int total = open_and_close(av[1]);
	solve(av[1], 0, total);
	//printf("%d\n", open_and_close(av[1]));
	return (0);
}
