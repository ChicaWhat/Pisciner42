#include <unistd.h>
#include <stdio.h>

int ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int n = 0;
	int result = 0;
		if (is_valid_base(str_base) == 0)
				return (0);
	if (str[i] == '+' || str[i] == '-')
	{
			if (str[i] == '-')
					sign *= -1;
			i++;
	}
	while (str[i] != '\0')
	{
			if (str[i] >= '0' && str[i] <= '9')
					n = str[i] - '0';
			else if (str[i] >= 'A' && str[i] <= 'F')
					n = str[i] - 'A' + 10;
			else if (str[i] >= 'a' && str[i] <= 'f')
					n = str[i] - 'a' + 10;
			i++;
	}
	if (n <= str_base)
		result = result * str_base + n;
	return (result * sign);
}

int is_valid_base(int base)
{
		if (base >= 2 && base < 17)
				return (1);
		else
				return (0);
}
