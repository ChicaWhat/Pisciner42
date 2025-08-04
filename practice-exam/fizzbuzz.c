#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int num)
{
		char	d;

		d = num;
		if (num >= 10)
				ft_putnbr(num / 10);
		d = (num % 10) + '0';
		write(1, &d, 1);
}

void	ft_fizzbuzz(int num)
{
		num = 1;
		while (num <= 100)
		{
			if (num % 3 == 0 && num % 5 == 0)
			{
					write(1, "fizzbuzz", 8);
					write(1, "\n", 1);
			}
			else if (num % 3 == 0)
			{
					write(1, "fizz", 4);
					write(1, "\n", 1);
			}
			else if (num % 5 == 0)
			{
					write(1, "buzz", 4);
					write(1, "\n", 1);
			}
			else
			{
					ft_putnbr(num);
					write(1, "\n", 1);
			}
			num++;
		}
}

/* int	main(void)
{
	int num = 1;
		ft_fizzbuzz(num);
		return (0);
} */
