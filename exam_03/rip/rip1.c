#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	open_and_close(char *s)
{
	int i = 0;
	int o = 0;
	int c = 0;
	while (s[i])
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
	return (c + o);
}

void	solve(char *s, int i, int total)
{
	if (!s[i])
	{
		if (total == 0 && open_and_close(s) == 0)
		{
			puts(s);
			return ;
		}
	}
	char tmp = s[i];
	if (s[i])
	{
		if ((s[i] == '(' || s[i] == ')') && total > 0)
		{
			s[i] = ' ';
			solve(s, i + 1, total - 1);
		}
		s[i] = tmp;
		solve(s, s + 1, total);
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int i = 0;
	int total = open_and_close(av[1]);
	solve(&av[1][i], 0, total);
	return (0);
}
