#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_isspace(char c)
{
	/* El return de abajo es EXACTAMENTE LO MISMO que lo siguiente:
	 * if (c == 32 || c == '\t')
	 * 	return (1);
	 * return (0);
	 * */
	return (c == 32 || c == '\t');	
}

char ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		 c += 32;
	return (c);
}

int ft_isbase(int n_base)
{
	return (n_base >= 2 && n_base <= 16);
}

int ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int num = 0;
	int sign = 1;
	int result = 0;

	if (!ft_isbase(str_base))
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = str[i] - '0';
		else if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
			num = ft_tolower(str[i]) - 'a' + 10;
		if (num > str_base)
			break;
		else
			result = result * str_base + num;
	       i++;	
	}
	return (result * sign);
}

int main(int ac, char **av)
{
	//(void)av;
	if (ac == 3)
	{
		printf("%d\n", ft_atoi_base(av[1], atoi(av[2])));
	}
	return (0);
}
