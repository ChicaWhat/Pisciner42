#include <unistd.h>

void ft_putnbr(int n)
{
		char d;
		if (n >= 10)
				ft_putnbr(n / 10);
		d = n % 10 + '0';
		write(1, &d, 1);
}

int main(int ac, char **av)
{
		int i = 0;
		//int arg = av[0];
		if (ac != 1)
		{
				while(av[i])
						i++;
				ft_putnbr(i - 1);
				write(1, "\n", 1);
		}
		else
		{
				write(1, "0", 1);
				write(1, "\n", 1);
		}
		return (0);
}

/*
	Llamo directamente a la funcion putnbr - 1
	ft_putnbr(ac - 1);
*/
