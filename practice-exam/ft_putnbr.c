#include <unistd.h>

void    ft_putnbr(int num)
{
        char    d;

        d = num;
        if (num >= 10)
        {
                ft_putnbr(num / 10);
        }
        d = ((num % 10) + '0');
        write (1, &d, 1);
	if (num < 10)
	{
        	write(1, "\n", 1);
	}
}

int	main(void)
{
	int	num;
	num = 42;
	while (num >= 42 && num <= 43)
	{
		ft_putnbr(num);
		num++;
	}
	return (0);
}
