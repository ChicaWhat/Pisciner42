#include <unistd.h>

void ft_putnbr(int n)
{
		char d;
		if (n >= 10)
		{
				ft_putnbr(n / 10);
		}
		d = n % 10 + '0';
		write(1, &d, 1);
}

int ft_atoi(char *str)
{
	int n = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == 32 || str[i] == 9)
		i++;
	
	if (str[i] == '+' || str[i] == '-')
	{
			if (str[i] == '-')
			{
					sign *= -1;
					i++;
			}
	}

	while (str[i])
	{
			if (str[i] >= '0' && str[i] <= '9')
				n = (n * 10) + (str[i] - '0');
			i++;
	}
	return (n * sign);
}

int isprime(int n)
{
		int i = 2;
		if (n < 2)
				return (0);
		while (i <= n / 2)
		{
				if (n % i == 0)
						return (0);
				i++;
		}
		return (1);
}

void add_prime_sume(char *s)
{
		int n = ft_atoi(s);
		int sum = 0;
		int i = 2;

		while  (i <= n)
		{
				if (isprime(i) == 1)
						sum += i;
				i++;
		}
		ft_putnbr(sum);
}

int main(int argc, char **argv)
{
	//int i = 0;
	if (argc != 2)
			write(1, "0", 1);
	else
	{
		add_prime_sume(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
