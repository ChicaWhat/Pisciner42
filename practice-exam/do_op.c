#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
		printf("\n");
		return (0);
}
