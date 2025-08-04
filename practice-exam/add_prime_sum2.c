#include <unistd.h>
#include <stdio.h>

void putnbr(int n)
{
	char d;
	if (num >= 10)
			putnbr(n / 10);
	d = n % 10 + '0';
}

int atoi(char *str)
{
		//Aqui va el atoi
}

int is_prime(int n)
{

}
