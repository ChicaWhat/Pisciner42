#include <unistd.h>
#include <stdio.h>

int atoi(char *str)
{
		int i = 0;
		int sign = 1;
		char num;
		while (str[i] <= 32)
				i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		//if (str[i] >= 10)
		//		num = atoi(str[i] / 10);
		if (str[i] >= '0' && str[i] <= '9')
				num = (str[i] * 10) - '0';
		//num = (num * 10) - '0';
		write(1, &num, 1);
		return (num);
}

int main(int argc, char **argv)
{
		int i = 0;
		int j = 0;

		if (argc == 3)
		{
				while (argv[1][i] != '\0' && argv[3][i] != '\0')
				{
					if (argv[2] == "+")

				}
		}
		write(1, "\n", 1);
		return (0);
}
