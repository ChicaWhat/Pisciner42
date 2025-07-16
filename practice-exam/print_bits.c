#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	print_bits(unsigned char octet)
{
	int num = 128;
	while (num >= 1)
	{
			if (octet >= num)
			{
					write(1, "1", 1);
					octet = octet - num;
			}
			else
					write(1, "0", 1);
			num = num / 2;
	}
}

int main(int argc, char **argv)
{
		int octet = atoi(argv[1]);
		if (argc == 2)
		{
			if (octet >= 0 && octet <= 255)
				print_bits((unsigned char)octet);
			else
				printf("Error: numero fuero de rango");
		}
		return (0);
}
