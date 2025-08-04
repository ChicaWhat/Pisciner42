#include <unistd.h>

void putnbr(int n)
{
		char d;
		if (n <= 10)
		{
				putnbr(n / 10);
		}
		d = n % 10 + '0';
		write(1, &d, 1);
}


int main(int argc, char **argv)
{
	int i = 0;
	char *num = argv[1];
	int digit = 0;
	if (argc == 2)
	{
		if (argv[1] < 0)
				return (0);
		while (num[i] >= '0' && num[i] <= '9')
		{
			digit = digit * 10 + (num[i] - '0');
			i++;
		}
		//if (num <= 1)
			//return (0);
	}
}
