#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// No necesito el atoi, pero weno
//int atoi(char *str)
//{
//		int i = 0;
//		int sign = 1;
//		char num = 0;
//		while (str[i] <= 32)
//				i++;
//		while (str[i] == '-' || str[i] == '+')
//		{
//			if (str[i] == '-')
//				sign *= -1;
//			i++;
//		}
//		if (str[i] >= '0' && str[i] <= '9')
//				num = (num * 10) + str[i] - '0';
//		write(1, &num, 1);
//		return (num);
//}

int main(int argc, char **argv)
{
		//int i = 0;
		//int j = 0;
		int a = atoi(argv[1]);
		int b = atoi(argv[3]);
		char operator = argv[2][0];
		int result = 0;

		if (argc == 4)
		{
			if (operator == '+')
				result = a + b;
			else if (operator == '-')
				result = a - b;
			else if (operator == '*')
				result = a * b;
			else if (operator == '/')
				result = a / b;
			else if (operator == '%')
				result = a % b;
			printf("%d", result);
		}
		//printf("%d", result);
		write(1, "\n", 1);
		return (0);
}
