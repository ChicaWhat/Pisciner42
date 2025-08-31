#include <unistd.h>

char ft_putnbr(int n)
{
		char d;
		if (n >= 10)
				ft_putnbr(n / 10);
		d = n % 10 + '0';
		write(1, &d, 1);
		return (d);
}

int ft_atoi(char *str)
{
		int i = 0;
		//int sign = 1;
		int n = 0;
		if (!str)
				return (0);
		while (str[i])
		{
				if (str[i] >= '0' && str[i] <= '9')
						n = (n * 10) + (str[i] - '0');
				i++;
		}
		return (n);
}

int main(int ac, char **av)
{
		int i = 1;
		int n = ft_atoi(av[1]);
		int res = 0;

		if (ac == 2)
		{
				while (i <= 9)
				{
						res = i * n;
						ft_putnbr(i);
						write(1, " x ", 3);
						ft_putnbr(n);
						write(1, " = ", 3);
						ft_putnbr(res);
						write(1, "\n", 1);
						i++;
				}
		}
		else
			write(1, "\n", 1);
		return (0);
}
